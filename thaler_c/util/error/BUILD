cc_library(
    name = "error",
    srcs = ["error.c"],
    hdrs = ["error.h"],
)

cc_test(
    name = "error_test",
    size = "small",
    srcs = ["error_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":error"
    ],
)