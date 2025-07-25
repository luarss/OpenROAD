# gcd_nangate45 IO placement
source "helpers.tcl"
read_lef Nangate45/Nangate45.lef
read_def gcd.def

set_io_pin_constraint -direction INPUT -region right:*
set_io_pin_constraint -direction OUTPUT -region left:*
place_pins -hor_layers metal3 -ver_layers metal2 -corner_avoidance 0 -min_distance 0.12 -annealing

set def_file [make_result_file annealing_constraint4.def]

write_def $def_file

diff_file annealing_constraint4.defok $def_file
