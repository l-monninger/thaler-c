#include "thaler_c/util/math/category/arity.h"
#include "thaler_c/util/math/set/set.h"

#define Fieldlike(typename) \
    Setlike(typename); \
    MUTA2(add, typename); \
    MUTA2(subtract, typename); \
    MUTA2(multiply, typename); \
    MUTA2(divide, typename); 

typedef struct Field {
    Fieldlike(void *)
} Field;
