cc_library(
    name = "tha_error",
    srcs = ["tha_error.c"],
    hdrs = ["tha_error.h"],
    visibility = [
        "//visibility:public"
    ]
)

cc_test(
    name = "tha_error_test",
    size = "small",
    srcs = ["tha_error_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":tha_error"
    ],
)