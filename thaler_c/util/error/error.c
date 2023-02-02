#include <stdlib.h>
#include <stdio.h>
#include "error.h"

/**
 * @brief 
 * 
 * @param label 
 * @param reason 
 * @param file 
 * @param line 
 * @param tha_errno 
 */
int tha_error (
    enum ThaErrno tha_errno,
    const char *label,
    const char *reason, 
    const char *file, 
    int line
){

    int err = fprintf(stderr, "thaler (%d): %s:%d: %s: %s\n", tha_errno, file, line, label, reason);
    if(err < 0){
        abort();
        return THA_FAILURE;
    }
    err = fflush(stderr);
    if(err != 0) {
        abort();
        return THA_FAILURE;
    }

    SUC;

}
