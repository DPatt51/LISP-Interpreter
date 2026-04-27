#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <unordered_map>

int evaluate(std::vector<std::string>& tokens, int& pos, std::unordered_map<std::string, int>& env);

#endif