#include "hw1.h"

PostfixExpressionEvaluator::Result
PostfixExpressionEvaluator::evaluate_expression(std::istream & input, int_t min, int_t max) {
    return Result{};
}

std::ostream & operator<<(std::ostream & os, PostfixExpressionEvaluator::Result result) {
    return os << "min=" << result.min << " max=" << result.max;
}