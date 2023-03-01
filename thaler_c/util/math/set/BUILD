# set
cc_library(
    name = "set",
    srcs = ["set.c"],
    hdrs = ["set.h"],
    deps = [
        "//thaler_c/util/math/category:truth"
    ],
    visibility = [
        "//visibility:public"
    ]
)

cc_test(
    name = "set_test",
    size = "small",
    srcs = ["set_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":set"
    ],
)
