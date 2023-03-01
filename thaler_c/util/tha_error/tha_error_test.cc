#include <gtest/gtest.h>
extern "C" {
    #include "tha_error.h"
}
#include "stdlib.h"
#include "stddef.h"

int doThing(){

    SUC;

}

int doFailedThing(){

    THROW(THA_FAILURE, "GENERIC_FAILURE", "It didn't work.");

}

TEST(Succeeds, BasicSuccess){

    int flag = doThing();

    EXPECT_EQ(flag, THA_SUCCESS);

}

TEST(Fails, BasicFailure){

    testing::internal::CaptureStderr();
    int flag = doFailedThing();
    std::string output = testing::internal::GetCapturedStderr();
    // std::cerr << "MADE IT: " << output << std::endl; // this is useful whe debugging/changing error message format
    EXPECT_EQ(flag, THA_FAILURE);
    EXPECT_EQ(output, "tha_error(-1) in {doFailedThing} at [thaler_c/util/tha_error/tha_error_test.cc:16] #GENERIC_FAILURE: It didn't work.\n");

}