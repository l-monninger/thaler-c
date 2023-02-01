#include <gtest/gtest.h>
extern "C" {
    #include "matrix.h"
}
#include "stdlib.h"
#include "stddef.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(CreatesMatrix, BasicAssertions){

    Matrix *result = NULL;
    size_t dims[2] = {4, 4};
    malloc_matrix(dims, result, 1);

}