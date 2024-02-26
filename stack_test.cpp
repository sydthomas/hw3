#include <gtest/gtest.h>

#include "stack.h"

// Test case to check if stack is initially empty
TEST_F(StackTest, IsEmptyInitially) {
    EXPECT_TRUE(stack.isEmpty());
}

// Test case to check if stack is not empty after pushing an element
TEST_F(StackTest, IsNotEmptyAfterPush) {
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());
}

// Test case to check top after pushing elements
TEST_F(StackTest, TopAfterPush) {
    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
}

// Test case to check pop
TEST_F(StackTest, Pop) {
    stack.push(10);
    stack.push(20);
    stack.pop();
    EXPECT_EQ(stack.top(), 10);
}

// Test case to check if pop works correctly on an empty stack
TEST_F(StackTest, PopEmptyStack) {
    // We expect nothing to happen when we pop from an empty stack
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

// Test case to check top on an empty stack
TEST_F(StackTest, TopEmptyStack) {
    // Top on an empty stack should throw an exception
    ASSERT_THROW(stack.top(), std::runtime_error);
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}