#include <iostream>
#include <gtest/gtest.h>

#include "hw1.h"

using int_t = PostfixExpressionEvaluator::int_t;

// Add your own tests for:
// * parsing and evaluating simple expressions for given input ranges
// * evaluating intermediate format expressions with just single input variable,
//   i.e. as if min == max
// * any more complex function you write and are unsure about its correctness
// * corner cases e.g. division by 0 - need some error handling
//    * don't use exceptions just yet, try to return invalid Result and verify that in this test

TEST(TestEvaluation, SingleAddition) {
    std::stringstream input{"1 x +"};
    int_t const min = 2;
    int_t const max = 4;

    auto evaluator = PostfixExpressionEvaluator{};
    auto result = evaluator.evaluate_expression(input, min, max);

    auto expected = PostfixExpressionEvaluator::Result{.min=3, .max=5};
    ASSERT_EQ(result, expected);
}

TEST(TestEvaluation, Recodex) {
    std::stringstream input{"14 x 71 /+3000"
                            "x-75/*"};
    int_t const min = 0;
    int_t const max = 1;

    auto evaluator = PostfixExpressionEvaluator{};
    auto result = evaluator.evaluate_expression(input, min, max);

    auto expected = PostfixExpressionEvaluator::Result{.min=546, .max=560};
    ASSERT_EQ(result, expected);
}

TEST(TestPrint, Print) {
    std::stringstream output{};

    auto result = PostfixExpressionEvaluator::Result{.min=-10, .max=20};
    output << result;

    ASSERT_EQ(output.str(), "min=-10 max=20");
}
