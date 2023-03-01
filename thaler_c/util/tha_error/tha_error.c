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

    int err = fprintf(stderr, "tha_error(%d) in {%s} at [%s:%d] #%s: %s\n", tha_errno, func, file, line, label, reason);
    if(err < 0){ // if you can't write to stderr, that's an irrecoverable problem
        abort();
        return THA_FAILURE;
    }
    err = fflush(stderr);
    if(err != 0) { // if you can't flush stderr, that's an irrecoverable problem
        abort();
        return THA_FAILURE;
    }

    SUC;

}
