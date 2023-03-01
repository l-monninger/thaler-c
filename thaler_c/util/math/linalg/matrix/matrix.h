#pragma once
#include "stddef.h"
#include "thaler_c/util/math/set/field/field.h"
#include "thaler_c/util/math/category/get.h"

#define Matrixlike(typename) \
    Fieldlike(typename) \
    size_t dims[2]; \
    typename* values; \
    MUTG0(get_zero, typename); \
    MUTG0(get_one, typename);


typedef struct Matrix {
    Matrixlike(void*)
} Matrix;

typedef struct IntMatrix {
    Matrixlike(int)
} IntMatrix;

// define a function pointer type
typedef int (*free_r)(void*);

// members
int malloc_matrix(size_t dims[2], Matrix **result, size_t size);
int calloc_matrix(size_t dims[2], Matrix **result, size_t size);
int gat(Matrix *M, size_t dims[2], void ***result);
int sat(Matrix *M, size_t dims[2], void *value);

