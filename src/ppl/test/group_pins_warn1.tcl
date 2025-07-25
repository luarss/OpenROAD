# exclude horizontal edges
source "helpers.tcl"
read_lef Nangate45/Nangate45.lef
read_def gcd.def

place_pins -hor_layers metal3 -ver_layers metal2 -corner_avoidance 0 \
  -min_distance 0.12 -group_pins {resp_val resp_rdy req_rdy} \
  -group_pins {req_msg[15] req_msg[14] resp_msg[15] resp_msg[141]}

set def_file [make_result_file group_pins_warn1.def]

write_def $def_file

diff_file group_pins_warn1.defok $def_file
