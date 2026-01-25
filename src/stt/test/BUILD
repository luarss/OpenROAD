load("//test:regression.bzl", "regression_test")

package(features = ["layering_check"])

COMPULSORY_TESTS = [
    "check",
    "flute1",
    "flute_gcd",
    "parse_clocks",
    "pd1",
    "pd2",
    "pd_gcd",
]

MANUAL_TESTS = [
    "stt_readme_msgs_check",
    "stt_man_tcl_check",
]

TESTS = COMPULSORY_TESTS + MANUAL_TESTS

filegroup(
    name = "doc_test_resources",
    srcs = [
        "extract_utils.py",
        "md_roff_compat.py",
        "//src/stt:README.md",
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
            for test in TESTS
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
            "stt_readme_msgs_check": [
                ":doc_test_resources",
                "//src/stt:messages.txt",
            ],
            "stt_man_tcl_check": [
                ":doc_test_resources",
                "//src/stt:src/SteinerTreeBuilder.tcl",
            ],
        }.get(test_name, [])),
        tags = [] if test_name in COMPULSORY_TESTS else ["manual"],
    )
    for test_name in TESTS
]
