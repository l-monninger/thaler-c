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
    std::cerr << "MADE IT: " << output << std::endl;
    EXPECT_EQ(flag, THA_FAILURE);
    EXPECT_EQ(output, "thaler (-1): error_test.cc:16: GENERIC_FAILURE: It didn't work.\n");

}