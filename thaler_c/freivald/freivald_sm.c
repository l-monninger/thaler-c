#include "thaler_c/util/math/linalg/matrix.h"
#include "thaler_c/util/math/linalg/multiply.h"
#include "thaler_c/util/tha_error/tha_error.h"

/**
 * @brief 
 * 
 * @param A 
 * @param B 
 * @param C 
 * @param result 
 * @return int 
 */
int freivald_sm(Matrix *A, Matrix *B, Matrix *C, int *result){

    // 
    int flag = 0;
    void **x = NULL;
    void **Bx = NULL;
    void **ABx = NULL;
    void **Cx = NULL;

    MARK(
        flag, 
        mat_mult_vec(B, x, Bx),
        "MAT_MULT_VEC_ERROR",
        "Failed to compute Bx."
    );

    MARK(
        flag,
        mat_mult_vec(A, Bx, ABx),
        "MAT_MULT_VEC_ERROR",
        "Failed to compute ABx."
    );

    MARK(
        flag,
        mat_mult_vec(C, x, Cx),
        "MAT_MULT_VEC_ERROR",
        "Failed to compute Cx."
    );

    SUC;

}