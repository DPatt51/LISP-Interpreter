#include "parser.h"
#include <stdexcept>
#include <unordered_map>

int evaluate(std::vector<std::string>& tokens, int& pos, std::unordered_map<std::string, int>& env) {
    if (tokens[pos] == "(") {
        pos++; // skip '('
        std::string op = tokens[pos++];

        if (op == "define") {
            std::string varName = tokens[pos++];
            int value = evaluate(tokens, pos, env);
            env[varName] = value;
            
            while (tokens[pos] != ")") pos++; // skip extra just in case
            pos++; // skip ')'
            
            return value;
        }

        int result = evaluate(tokens, pos, env);

        while (tokens[pos] != ")") {
            int value = evaluate(tokens, pos, env);

            if (op == "+") result += value;
            else if (op == "-") result -= value;
            else if (op == "*") result *= value;
            else if (op == "/") {
                if (value == 0) throw std::runtime_error("Division by zero");
                result /= value;
            }
            else throw std::runtime_error("Unknown operator");
        }

        pos++; // skip ')'
        return result;
    }
    else {
        // Check if it's a number or a variable
        std::string token = tokens[pos++];

        try {
            return std::stoi(token);
        } catch (...) {
            if (env.find(token) != env.end()) {
                return env[token];
            } else {
                throw std::runtime_error("Undefined variable: " + token);
            }
        }
    }
}