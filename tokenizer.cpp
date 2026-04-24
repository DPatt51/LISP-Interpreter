#include "tokenizer.h"
#include <sstream>

std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;

    for (char c : input) {
        if (c == '(' || c == ')') {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(std::string(1, c));
        } else if (isspace(c)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}