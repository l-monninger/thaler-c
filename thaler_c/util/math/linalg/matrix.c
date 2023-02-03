#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include "thaler_c/util/tha_error/tha_error.h"

/**
 * @brief Mallocs a matrix with the provided dimensions.
 * 
 * @param dims 
 * @param result 
 * @param size 
 * @return int 
 */
int malloc_matrix(size_t dims[2], Matrix **result, size_t size){

    size_t height = dims[0];
    size_t width = dims[1];
    void **values = (void **) malloc(height * width * size);
    *result = (struct Matrix*) malloc(sizeof(Matrix));
    (*result)->dims[0] = height;
    (*result)->dims[1] = width;
    (*result)->values = values;

    return 0;

}

/**
 * @brief Callocs a matrix with the provided dimensions.
 * 
 * @param dims 
 * @param result 
 * @param size 
 * @return int 
 */
int calloc_matrix(size_t dims[2], Matrix **result, size_t size){

    size_t height = dims[0];
    size_t width = dims[1];
    void **values = (void **) calloc(height * width, size);
    *result = (struct Matrix*) malloc(sizeof(struct Matrix));
    (*result)->dims[0] = height;
    (*result)->dims[1] = width;
    (*result)->values = values;

    return 0;

}

/**
 * @brief Frees a matrix.
 * 
 * @param M 
 * @param free_value is a procedure for freeing values in the matrix.
 * @return int 
 */
int free_matrix(Matrix *M, free_r free_value){

    void **iter = M->values;
    int flag;


    for( ; iter; ++iter){
        flag = free_value(*iter);
        if(flag) return -1; // TODO: include Error handling
    }

    free(M);

    return 0;

}

/**
 * @brief Gets a pointer to a matrix value at an index.
 * 
 * @param M is the matrix.
 * @param dims is the location in the matrix
 * @param result is the pointer value which should be updated.
 * @return int an error flag.
 */
int gat(Matrix *M, size_t dims[2], void ***result){

    if(!M) return -1; // TODO: update with error

    size_t height = M->dims[0];
    size_t width = M->dims[1];
    size_t m = dims[0];
    size_t n = dims[1];

    if(m < 0 || n < 0 || m > (height - 1) || n > (width - 1)) 
        return -2; // TODO: Update to error.

    *result = M->values + ((m * width) + n);

    return 0;

}

/**
 * @brief Sets a matrix at an index.
 * 
 * @param M is the matrix.
 * @param dims identify the location in the matrix.
 * @param value is the value to update the location in the matrix to.
 * @return int an error flag.
 */
int sat(Matrix *M, size_t dims[2], void *value){

    void **ptr = NULL; 
    int res = gat(M, dims, &ptr);

    if(res != 0)
        return -1; // TODO: Update to error handling.

    *ptr = value;
    return res;

}