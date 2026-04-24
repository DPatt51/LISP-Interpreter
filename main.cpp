#include <iostream>
#include "tokenizer.h"
#include "parser.h"

int main() {
    std::string input;

    std::cout << "LISP Interpreter\n";

    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        try {
            auto tokens = tokenize(input);
            int pos = 0;
            int result = evaluate(tokens, pos);
            std::cout << result << std::endl;
        } catch (...) {
            std::cout << "Error evaluating expression\n";
        }
    }

    return 0;
}