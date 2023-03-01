#include "thaler_c/util/math/category/truth.h"
#include "thaler_c/util/math/set/set.h"

#define VEC_ADD(name, typename) \
    int (*name)(typename *, typename *, typename *)

#define SCALE(name, typename) \
    int (*name)(typename, typename *, typename *)

// NOTE: typename here should represent the elements 

// A vector space is a set equipped with...
// 1. Vector addition
// 2. Vector scaling
#define VectorSpacelike(typename) \
    Setlike(typename) \
    VEC_ADD(vec_add, typename) \
    SCALE(scale, typename)


typedef struct VectorSpace {
    Setlike(void *)
} VectorSpace;