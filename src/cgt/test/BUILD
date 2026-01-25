# SPDX-License-Identifier: BSD-3-Clause
# Copyright (c) 2025, The OpenROAD Authors
load("//test:regression.bzl", "regression_test")

package(features = ["layering_check"])

# From CMakeLists.txt or_integration_tests(TESTS
COMPULSORY_TESTS = [
    "aes_nangate45",
    "countdown_asap7",
    "ibex_sky130hd",
]

MANUAL_TESTS = [
    "cgt_man_tcl_check",
    "cgt_readme_msgs_check",
]

ALL_TESTS = COMPULSORY_TESTS + MANUAL_TESTS

filegroup(
    name = "regression_resources",
    # Dependencies could be specified more narrowly per test case,
    # but at least it is not a glob of everything and there are
    # per test glob patterns below.
    srcs = [
        "helpers.tcl",
    ],
)

filegroup(
    name = "doc_test_resources",
    srcs = [
        "extract_utils.py",
        "md_roff_compat.py",
        "//src/cgt:README.md",
    ],
)

[
    filegroup(
        name = test_name + "_resources",
        srcs = [":regression_resources"] + glob(
            [
                test_name + "*",
            ] + {
                "aes_nangate45": [
                    "Nangate45/Nangate45.lef",
                    "Nangate45/Nangate45_stdcell.lef",
                    "Nangate45/Nangate45_typ.lib",
                ],
                "countdown_asap7": [
                    "asap7/asap7_tech_1x_201209.lef",
                    "asap7/asap7sc7p5t_28_R_1x_220121a.lef",
                    "asap7/asap7sc7p5t_AO_RVT_FF_nldm_211120.lib.gz",
                    "asap7/asap7sc7p5t_INVBUF_RVT_FF_nldm_220122.lib.gz",
                    "asap7/asap7sc7p5t_OA_RVT_FF_nldm_211120.lib.gz",
                    "asap7/asap7sc7p5t_SEQ_RVT_FF_nldm_220123.lib",
                    "asap7/asap7sc7p5t_SIMPLE_RVT_FF_nldm_211120.lib.gz",
                ],
                "ibex_sky130hd": [
                    "sky130hd/sky130_fd_sc_hd__ss_n40C_1v40.lib",
                    "sky130hd/sky130hd.tlef",
                    "sky130hd/sky130hd_std_cell.lef",
                ],
                "cgt_readme_msgs_check": [
                    ":doc_test_resources",
                    "//src/cgt:messages.txt",
                ],
                "cgt_man_tcl_check": [
                    ":doc_test_resources",
                    "//src/cgt:src/cgt.tcl",
                ],
            }.get(test_name, []),
        ),
    )
    for test_name in ALL_TESTS
]

[
    regression_test(
        name = test_name,
        data = [":" + test_name + "_resources"],
        tags = [] if test_name in COMPULSORY_TESTS else ["manual"],
        visibility = ["//visibility:public"],
    )
    for test_name in ALL_TESTS
]
