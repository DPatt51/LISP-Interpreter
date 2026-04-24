#include "parser.h"
#include <stdexcept>

int evaluate(std::vector<std::string>& tokens, int& pos) {
    if (tokens[pos] == "(") {
        pos++; // skip '('
        std::string op = tokens[pos++];
        
        int result = evaluate(tokens, pos);

        while (tokens[pos] != ")") {
            int value = evaluate(tokens, pos);

            if (op == "+") result += value;
            else if (op == "-") result -= value;
            else if (op == "*") result *= value;
            else if (op == "/") {
                if (value == 0) {
                    throw std::runtime_error("Division by zero");
                }
                result /= value;
            }
            else if (op == "-") {
                if (tokens[pos] == ")") return -result;
                result -= value;
                }
            else throw std::runtime_error("Unknown operator");
        }

        pos++; // skip ')'
        return result;
    }else {
        return std::stoi(tokens[pos++]);
    }
}