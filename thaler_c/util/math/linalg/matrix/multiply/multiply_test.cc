#include <gtest/gtest.h>
extern "C" {
    #include "multiply.h"
}
#include "stdlib.h"
#include "stddef.h"

int multiply(void *a, void *b){
    
    return (*(unsigned int *) &a) * (*(unsigned int *) &b);
    
}

TEST(Multiply, SmallMatrix){

    /*int flag = 0;
    int benchmark[3] = {11, 31, 11};
    int x[3] = {2, 3, -1};
    size_t dims[2] = {3, 3};
    Matrix *M = NULL;

    flag = calloc_matrix(dims, &M, sizeof(int));*/

    float a = 2.5;
    float b = 2.5;
    
    printf("%f\n", (float) multiply((void *)(uintptr_t)a, (void *)(uintptr_t)b));

}
