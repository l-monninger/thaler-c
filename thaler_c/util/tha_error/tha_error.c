#include <stdlib.h>
#include <stdio.h>
#include "tha_error.h"

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
    const char *func,
    const char *file, 
    int line,
    const char *label,
    const char *reason
){

    int err = fprintf(stderr, "thaler (%d) in %s at %s:%d: %s: %s\n", tha_errno, func, file, line, label, reason);
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
