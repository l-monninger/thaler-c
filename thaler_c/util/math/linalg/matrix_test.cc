#include <gtest/gtest.h>
extern "C" {
    #include "matrix.h"
}
#include "stdlib.h"
#include "stddef.h"

TEST(CreatesMatrix, BasicAssertions){

  Matrix *M = NULL;
  size_t dims[2] = {4, 4};
  calloc_matrix(dims, &M, sizeof(int));

  void **entry = NULL;
  size_t pos[2] = {0, 0};
  int res = gat(M, pos, &entry);
  EXPECT_EQ( *(int *)entry, 0);

  // mutate in place
  *entry = (void *) 2;
  void **second_entry = NULL;
  int another_res = gat(M, pos, &second_entry);
  EXPECT_EQ( *(int *)second_entry, 2);

  // set
  int set_res = sat(M, pos, (void *) 3);
  EXPECT_EQ( *(int *)second_entry, 3);

}