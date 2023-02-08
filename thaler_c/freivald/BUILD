# freivald
cc_library(
    name = "freivald",
    srcs = ["freivald.c"],
    hdrs = ["freivald.h"],
    deps = [
        "//thaler_c/util/tha_error:tha_error",
        "//thaler_c/util/math/linalg:matrix",
        "//thaler_c/util/math/linalg:multiply"
    ]
)

cc_test(
    name = "freivald_test",
    size = "small",
    srcs = ["freivald_test.cc"],
    deps = [
        "@com_google_googletest//:gtest_main",
        ":freivald"
    ],
)
