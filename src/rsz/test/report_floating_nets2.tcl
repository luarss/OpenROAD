# report_floating_nets
source "helpers.tcl"
read_liberty Nangate45/Nangate45_typ.lib
read_lef Nangate45/Nangate45.lef
read_verilog report_floating_nets2.v
link_design top
report_floating_nets
report_floating_nets -verbose
