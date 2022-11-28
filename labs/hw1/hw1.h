#pragma once

#include <cstdint>
#include <iostream>

struct PostfixExpressionEvaluator {
    using int_t = int32_t;

    struct Result {
        int_t min;
        int_t max;

        bool operator==(const Result & other) const {
            return min == other.min && max == other.max;
        }
    };
    
    Result evaluate_expression(std::istream & input, int_t min, int_t max);
};

std::ostream & operator<<(std::ostream & os, PostfixExpressionEvaluator::Result result);
