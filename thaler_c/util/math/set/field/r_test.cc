#include <gtest/gtest.h>
extern "C" {
    #include "r.h"
}
#include "stdlib.h"
#include "stddef.h"

int multiply(int a, int b, int *c){

    *c = a * b;

    return 1;

}

TEST(RField, Ptr){

    int res;
    (&R)->multiply(1, 2, &res);
    ASSERT_EQ(res, 2);

}

TEST(RField, SimpleAdds){

    int res;
    R.add(1, 2, &res);
    ASSERT_EQ(res, 3);

}

TEST(RField, SimpleSubtracts){

    int res;
    R.subtract(2, 1, &res);
    ASSERT_EQ(res, 1);

}

TEST(RField, SimpleMultiplies){

    int res;
    R.multiply(1, 2, &res);
    ASSERT_EQ(res, 2);

}

// quick benchmark test
TEST(RField, MultipliesALot){

    int res;
    int flag;

    const clock_t t0 = clock(); // or gettimeofday or whatever
    auto m = R.multiply;
    for(int i = 0; i < 0xa107; ++i){
        asm("\n # fieldmult");
        flag = m(i, 2, &res);
        asm("\n # endfieldmult");
    }
    const clock_t t1 = clock();
    const double elapsedSec = (t1 - t0) / (double)CLOCKS_PER_SEC;
    std::cerr << "INLINED: " << elapsedSec << std::endl; // this is useful whe debugging/changing error message format

    const clock_t t2 = clock(); // or gettimeofday or whatever
    for(int i = 0; i < 0xa107; ++i){
        asm("\n # opmult");
        res = i * 2;
        flag = 1;
        asm("\n # endopmult");
    }
    const clock_t t3 = clock();
    const double elapsedSec2 = (t3 - t2) / (double)CLOCKS_PER_SEC;
    std::cerr << "OPERATOR: " << elapsedSec2 << std::endl; // this is useful whe debugging/changing error message format

    const clock_t t4 = clock(); // or gettimeofday or whatever
    for(int i = 0; i < 0xa107; ++i){
        flag = multiply(i, 2, &res);
    }
    const clock_t t5 = clock();
    const double elapsedSec3 = (t5 - t4) / (double)CLOCKS_PER_SEC;
    std::cerr << "NON-INLINED: " << elapsedSec3 << std::endl; // this is useful whe debugging/changing error message format

}

TEST(RField, SimpleDivides){

    int res;
    R.divide(4, 2, &res);
    ASSERT_EQ(res, 2);

}