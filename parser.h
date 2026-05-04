#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <unordered_map>

struct Function{
    std::vector<std::string> params;
    std::vector<std::string> body;
};

int evaluate(
    std::vector<std::string>& tokens,
    int& pos,
    std::unordered_map<std::string, int>& env,
    std::unordered_map<std::string, Function>& functions
);

#endif