# SPDX-License-Identifier: BSD-3-Clause
# Copyright (c) 2022-2025, The OpenROAD Authors
load("//test:regression.bzl", "regression_test")

package(features = ["layering_check"])

# From CMakeLists.txt or_integration_tests(TESTS
COMPULSORY_TESTS = [
    "supported",
]

MANUAL_TESTS = [
    "gui_readme_msgs_check",
    "gui_man_tcl_check",
]

ALL_TESTS = COMPULSORY_TESTS + MANUAL_TESTS

filegroup(
    name = "doc_test_resources",
    srcs = [
        "extract_utils.py",
        "md_roff_compat.py",
        "//src/gui:README.md",
    ],
)

filegroup(
    name = "test_resources",
    # overly broad glob, could be refined later, but
    # symlinks are cheap and OpenROAD binary changes, the common
    # use case is that all tests have to be re-run.
    srcs = glob(
        ["**/*"],
        exclude = [
            test + "." + ext
            for test in ALL_TESTS
            for ext in [
                "tcl",
                "py",
            ]
        ],
    ),
)

[
    regression_test(
        name = test_name,
        data = [":test_resources"] + ({
            "gui_readme_msgs_check": [
                ":doc_test_resources",
                "//src/gui:messages.txt",
            ],
            "gui_man_tcl_check": [
                ":doc_test_resources",
                "//src/gui:src/gui.tcl",
            ],
        }.get(test_name, [])),
        tags = [] if test_name in COMPULSORY_TESTS else ["manual"],
        visibility = ["//visibility:public"],
    )
    for test_name in ALL_TESTS
]
