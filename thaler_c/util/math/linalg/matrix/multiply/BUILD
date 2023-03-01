# multiply
cc_library(
    name = "multiply",
    srcs = ["multiply.c"],
    hdrs = ["multiply.h"],
    deps = [
        "//thaler_c/util/tha_error:tha_error",
        ":matrix"
    ]
)

cc_test(
    name = "multiply_test",
    size = "small",
    srcs = ["multiply_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":multiply",
        # ":matrix"
    ],
)