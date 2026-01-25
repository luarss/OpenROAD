# SPDX-License-Identifier: BSD-3-Clause
# Copyright (c) 2022-2025, The OpenROAD Authors
load("//test:regression.bzl", "regression_test")

package(features = ["layering_check"])

# From CMakeLists.txt or_integration_tests(TESTS
COMPULSORY_TESTS = [
    "make_parasitics1",
    "make_parasitics2",
    "make_parasitics3",
    "make_parasitics4",
    "make_parasitics5",
    "make_parasitics6",
    "make_parasitics7",
]

# Disabled in CMakeLists.txt
MANUAL_TESTS = [
    "est_man_tcl_check",
    "est_readme_msgs_check",
]

ALL_TESTS = COMPULSORY_TESTS + MANUAL_TESTS

filegroup(
    name = "test_resources",
    # overly broad glob, could be refined later, but
    # symlinks are cheap and OpenROAD binary changes, the common
    # use case is that all tests have to be re-run.
    srcs = glob(
        ["**/*"],
        exclude = [
            test + "." + ext
            for test in TESTS
            for ext in [
                "tcl",
                "py",
            ]
        ],
    ),
)

filegroup(
    name = "doc_test_resources",
    srcs = [
        "extract_utils.py",
        "md_roff_compat.py",
        "//src/est:README.md",
    ],
)

[
    filegroup(
        name = test_name + "_resources",
        srcs = glob([test_name + "*"]) + {
            "est_readme_msgs_check": [
                ":doc_test_resources",
                "//src/est:messages.txt",
            ],
            "est_man_tcl_check": [
                ":doc_test_resources",
                "//src/est:src/EstimateParasitics.tcl",
            ],
        }.get(test_name, []),
    )
    for test_name in MANUAL_TESTS
]

[regression_test(
    name = test_name,
    data = [":test_resources"],
) for test_name in TESTS]

[
    regression_test(
        name = test_name,
        data = [":" + test_name + "_resources"],
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )
    for test_name in MANUAL_TESTS
]
