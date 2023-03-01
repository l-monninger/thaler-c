#include "field.h"
#include "thaler_c/util/tha_error/tha_error.h"

typedef struct IntField {
    Fieldlike(int)
} IntField;

static inline int r_equals(
    int a,
    int b,
    int *c
){

    *c = a == b;
    SUC;

}

static inline int r_contains(
    int a,
    int *c
){

    *c = 1;
    SUC;

}

static inline int r_add(
    int a,
    int b,
    int *c
){

    *c = a + b;
    SUC;

}

static inline int r_subtract(
    int a,
    int b,
    int *c
){

    *c = a - b;
    SUC;

}

static inline int r_multiply(
    int a,
    int b,
    int *c
){

    *c = a * b;
    SUC;

}

static inline int r_divide(
    int a,
    int b,
    int *c
){

    *c = a / b; // let program crash on division by zero
    SUC;

}

static struct IntField R = IntField {
    .contains = r_contains,
    .equals = r_equals,
    .add = r_add,
    .subtract = r_subtract,
    .multiply = r_multiply,
    .divide = r_divide
};