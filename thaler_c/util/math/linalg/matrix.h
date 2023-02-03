#include "stddef.h"

#define Matrixlike(type) \
    size_t dims[2]; \
    type* values;

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

