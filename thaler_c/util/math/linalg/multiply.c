#include "matrix.h"
#include "multiply.h"
#include "thaler_c/util/tha_error/tha_error.h"

/**
 * @brief Matrix multiply.
 * 
 * @note we're considering just having this use the filmus algorithm instead 
 * of providing any interface to the O(n^3) algorithm.
 * 
 * @param M is the left matrix.
 * @param N is the right matrix.
 * @param result is the result matrix.
 * @return int an error flag.
 */
int mat_mult(Matrix *M, Matrix *N, Matrix *result){

    SUC;

}

/**
 * @brief Provides a clearer implementation of Matrix by vector multiplication edge case, O(n^2).
 * 
 * @param M is the left matrix.
 * @param vec is the vector (1d matrix).
 * @param result is the resulting vector.
 * @return int an error flag.
 */
int mat_mult_vec(Matrix *M, void **vec, void **result){

    int sum;
    int flag;
    size_t pos[2] = {0, 0};
    void **val;

    for(int i = 0; i < M->dims[0] ;++i){
        sum = 0;
        for(int j = 0; M->dims[1]; ++j){

            pos[0] = i;
            pos[1] = j;

            MARK(
                flag,
                gat(M, pos, &val),
                "INDEX_ERROR",
                "Failed to get value of matrix at index while multiply by vector."
            );

            sum += ((int) *val) * ((int) vec[j]);

        }

        result[i] = sum;

    }

    SUC;

}