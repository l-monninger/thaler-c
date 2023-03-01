# field
cc_library(
    name = "field",
    srcs = ["field.c"],
    hdrs = ["field.h"],
    deps = [
        "//thaler_c/util/tha_error:tha_error",
        "//thaler_c/util/math/set:set",
        "//thaler_c/util/math/category:arity"
    ],
    visibility = [
        "//visibility:public"
    ]
)

cc_test(
    name = "field_test",
    size = "small",
    srcs = ["field_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":field"
    ],
)

cc_test(
    name = "field_bench",
    size = "small",
    srcs = ["field_bench.cc"],
    deps = [
        "@benchmark//:benchmark",
        ":field"
    ],
)

# R
cc_library(
    name = "r",
    srcs = ["r.c"],
    hdrs = ["r.h"],
    deps = [
        "//thaler_c/util/tha_error:tha_error",
        ":field"
    ]
)

cc_test(
    name = "r_test",
    size = "small",
    srcs = ["r_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":r"
    ],
)
