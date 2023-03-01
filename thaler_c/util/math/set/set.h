#include "thaler_c/util/math/category/truth.h"

#define Setlike(typename) \
    MUTT1(contains, typename); \
    MUTT2(equals, typename); 

typedef struct Set {
    Setlike(void *)
} Set;