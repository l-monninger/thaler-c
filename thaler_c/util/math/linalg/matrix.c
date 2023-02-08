#include "matrix.h"
#include "thaler_c/util/tha_error/tha_error.h"
#include <stdlib.h>
#include <stdio.h>

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

    SUC;

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

    SUC;

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
        if(flag) THROW(
            THA_FREE, 
            "FAILED_MATRIX_MEMBER_FREE", 
            "Could not free matrix member."
        );

    }

    free(M);

    SUC;

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

    if(!M) THROW(
        THA_NULLPTR, 
        "MATRIX_NULLPTR", 
        "A pointer to a Matrix is required to get at (gat) an index."
    ); // TODO: update with error

    size_t height = M->dims[0];
    size_t width = M->dims[1];
    size_t m = dims[0];
    size_t n = dims[1];

    if(m < 0 || n < 0 || m > (height - 1) || n > (width - 1)) 
        THROW(
            THA_EDOM,
            "MATRIX_INDEX_OBE",
            "The provided matrix index is out of bounds."
        );

    *result = M->values + ((m * width) + n);

    SUC;

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

    int flag;
    void **ptr = NULL; 

    MARK(
        flag,
        gat(M, dims, &ptr),
        "SAT_COULD_NOT_GAT",
        "Could not set at index because could not get pointer to index."
    );

    *ptr = value;
    
    SUC;

}