# SPDX-License-Identifier: BSD-3-Clause
# Copyright (c) 2022-2025, The OpenROAD Authors

load("@rules_cc//cc:cc_test.bzl", "cc_test")
load("//test:regression.bzl", "regression_test")

package(features = ["layering_check"])

# Disabled in CMakeLists.txt
MANUAL_TESTS = [
    "cut_man_tcl_check",
    "cut_readme_msgs_check",
]

filegroup(
    name = "doc_test_resources",
    srcs = [
        "extract_utils.py",
        "md_roff_compat.py",
        "//src/cut:README.md",
    ],
)

[
    filegroup(
        name = test_name + "_resources",
        srcs = glob([test_name + "*"]) + {
            "cut_readme_msgs_check": [
                ":doc_test_resources",
                "//src/cut:messages.txt",
            ],
            "cut_man_tcl_check": [
                ":doc_test_resources",
            ],
        }.get(test_name, []),
    )
    for test_name in MANUAL_TESTS
]

[
    regression_test(
        name = test_name,
        data = [":" + test_name + "_resources"],
        tags = ["manual"],
        visibility = ["//visibility:public"],
    )
    for test_name in MANUAL_TESTS
]

cc_test(
    name = "cut_abc_test",
    srcs = ["cpp/TestAbc.cc"],
    data = [
        "Nangate45/Nangate45_stdcell.lef",
        "Nangate45/Nangate45_tech.lef",
        "Nangate45/Nangate45_typ.lib",
        "aes_nangate45.v",
        "asap7/asap7_tech_1x_201209.lef",
        "asap7/asap7sc7p5t_28_R_1x_220121a.lef",
        "asap7/asap7sc7p5t_AO_RVT_FF_nldm_211120.lib.gz",
        "asap7/asap7sc7p5t_INVBUF_RVT_FF_nldm_220122.lib.gz",
        "asap7/asap7sc7p5t_OA_RVT_FF_nldm_211120.lib.gz",
        "asap7/asap7sc7p5t_SEQ_RVT_FF_nldm_220123.lib",
        "asap7/asap7sc7p5t_SIMPLE_RVT_FF_nldm_211120.lib.gz",
        "empty_cut_set.v",
        "side_outputs_extract.v",
        "side_outputs_extract_logic_depth.v",
        "simple_and_gate_extract.v",
        "sky130/sky130_fd_sc_hd__ss_n40C_1v40.lib",
        "sky130/sky130hd.tlef",
        "sky130/sky130hd_std_cell.lef",
        "sky130_const_cell.v",
    ],
    deps = [
        "//src/cut",
        "//src/dbSta",
        "//src/dbSta:dbReadVerilog",
        "//src/odb",
        "//src/sta:opensta_lib",
        "//src/tst",
        "//src/utl",
        "//third-party/abc:abc-lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
