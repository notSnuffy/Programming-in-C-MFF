#include <iostream>
#include <string>
#include <fstream>

#include "hw1.h"

int main(int argc, char * argv[]) {
    // Gracefully exit in case of invalid argc and argv
    // TODO: add additional checks
    if (argc < 4) {
        return 1;
    }
    std::ifstream input{argv[1]};
    PostfixExpressionEvaluator::int_t min = std::stol(argv[2]);
    PostfixExpressionEvaluator::int_t max = std::stol(argv[3]);

    PostfixExpressionEvaluator evaluator{};
    auto result = evaluator.evaluate_expression(input, min, max);
    std::cout << result;
    return 0;
}
