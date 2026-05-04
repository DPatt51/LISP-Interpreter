#include "parser.h"
#include <stdexcept>

std::vector<std::string> captureExpression(std::vector<std::string>& tokens, int& pos) {
    std::vector<std::string> expr;
    int depth = 0;

    do {
        if (tokens[pos] == "(") depth++;
        if (tokens[pos] == ")") depth--;

        expr.push_back(tokens[pos]);
        pos++;
    } while (pos < tokens.size() && depth > 0);

    return expr;
}

int evaluate(
    std::vector<std::string>& tokens,
    int& pos,
    std::unordered_map<std::string, int>& env,
    std::unordered_map<std::string, Function>& functions
) {
    if (pos >= tokens.size()) {
        throw std::runtime_error("Unexpected end of input");
    }

    if (tokens[pos] == "(") {
        pos++;

        std::string op = tokens[pos++];

        if (op == "define") {
            if (tokens[pos] == "(") {
                pos++;

                std::string functionName = tokens[pos++];
                std::vector<std::string> params;

                while (tokens[pos] != ")") {
                    params.push_back(tokens[pos++]);
                }

                pos++;

                std::vector<std::string> body = captureExpression(tokens, pos);

                if (tokens[pos] != ")") {
                    throw std::runtime_error("Expected closing parenthesis");
                }

                pos++;

                functions[functionName] = {params, body};

                return 0;
            } else {
                std::string varName = tokens[pos++];
                int value = evaluate(tokens, pos, env, functions);

                if (tokens[pos] != ")") {
                    throw std::runtime_error("Expected closing parenthesis");
                }

                pos++;

                env[varName] = value;
                return value;
            }
        }

        if (op == "+" || op == "-" || op == "*" || op == "/") {
            int result = evaluate(tokens, pos, env, functions);

            while (tokens[pos] != ")") {
                int value = evaluate(tokens, pos, env, functions);

                if (op == "+") result += value;
                else if (op == "-") result -= value;
                else if (op == "*") result *= value;
                else if (op == "/") {
                    if (value == 0) {
                        throw std::runtime_error("Division by zero");
                    }
                    result /= value;
                }
            }

            pos++;
            return result;
        }

        if (functions.find(op) != functions.end()) {
            Function function = functions[op];
            std::vector<int> args;

            while (tokens[pos] != ")") {
                args.push_back(evaluate(tokens, pos, env, functions));
            }

            pos++;

            if (args.size() != function.params.size()) {
                throw std::runtime_error("Incorrect number of arguments");
            }

            std::unordered_map<std::string, int> localEnv = env;

            for (int i = 0; i < function.params.size(); i++) {
                localEnv[function.params[i]] = args[i];
            }

            int bodyPos = 0;
            return evaluate(function.body, bodyPos, localEnv, functions);
        }

        throw std::runtime_error("Unknown operator or function");
    }

    std::string token = tokens[pos++];

    try {
        return std::stoi(token);
    } catch (...) {
        if (env.find(token) != env.end()) {
            return env[token];
        }

        throw std::runtime_error("Undefined variable");
    }
}