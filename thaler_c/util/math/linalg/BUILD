# matrix
cc_library(
    name = "matrix",
    srcs = ["matrix.c"],
    hdrs = ["matrix.h"],
    deps = [
        "//thaler_c/util/tha_error:tha_error"
    ]
)

cc_test(
    name = "matrix_test",
    size = "small",
    srcs = ["matrix_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":matrix"
    ],
)

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
        ":multiply"
    ],
)

