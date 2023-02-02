#include <stdlib.h>
#include <stdio.h>

enum ThaErrno { 
  THA_SUCCESS  = 0, 
  THA_FAILURE  = -1,
  THA_CONTINUE = -2,  /* iteration has not converged */
  THA_EDOM     = 1,   /* input domain error, e.g sqrt(-1) */
  THA_ERANGE   = 2,   /* output range error, e.g. exp(1e100) */
  THA_EFAULT   = 3,   /* invalid pointer */
  THA_EINVAL   = 4,   /* invalid argument supplied by user */
  THA_EFAILED  = 5,   /* generic failure */
  THA_EFACTOR  = 6,   /* factorization failed */
  THA_ESANITY  = 7,   /* sanity check failed - shouldn't happen */
  THA_ENOMEM   = 8,   /* malloc failed */
  THA_EBADFUNC = 9,   /* problem with user-supplied function */
  THA_ERUNAWAY = 10,  /* iterative process is out of control */
  THA_EMAXITER = 11,  /* exceeded max number of iterations */
  THA_EZERODIV = 12,  /* tried to divide by zero */
  THA_EBADTOL  = 13,  /* user specified an invalid tolerance */
  THA_ETOL     = 14,  /* failed to reach the specified tolerance */
  THA_EUNDRFLW = 15,  /* underflow */
  THA_EOVRFLW  = 16,  /* overflow  */
  THA_ELOSS    = 17,  /* loss of accuracy */
  THA_EROUND   = 18,  /* failed because of roundoff error */
  THA_EBADLEN  = 19,  /* matrix, vector lengths are not conformant */
  THA_ENOTSQR  = 20,  /* matrix not square */
  THA_ESING    = 21,  /* apparent singularity detected */
  THA_EDIVERGE = 22,  /* integral or series is divergent */
  THA_EUNSUP   = 23,  /* requested feature is not supported by the hardware */
  THA_EUNIMPL  = 24,  /* requested feature not (yet) implemented */
  THA_ECACHE   = 25,  /* cache limit exceeded */
  THA_ETABLE   = 26,  /* table limit exceeded */
  THA_ENOPROG  = 27,  /* iteration is not making progress towards solution */
  THA_ENOPROGJ = 28,  /* jacobian evaluations are not improving the solution */
  THA_ETOLF    = 29,  /* cannot reach the specified tolerance in F */
  THA_ETOLX    = 30,  /* cannot reach the specified tolerance in X */
  THA_ETOLG    = 31,  /* cannot reach the specified tolerance in gradient */
  THA_EOF      = 32   /* end of file */
};

#define SUC \
    do { \
        return THA_SUCCESS; \
    } while (0)

/**
 * @brief 
 * 
 */
#define THROW(tha_errno, label, reason) \
    do { \
        tha_error (tha_errno, label, reason, __FILE__, __LINE__) ; \
        return tha_errno; \
    } while (0)

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
);

