############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project p00
set_top ircam04
add_files ../source/ircam04.cpp -cflags "-I /home/joo/work/fpga/hls/Vitis_Libraries/vision/L1/include"
add_files -tb ../tb/tb_top.cpp -cflags "-I../../Vitis_Libraries/vision/L1/include"
open_solution "solution1" -flow_target vivado
set_part {xc7a200tfbg484-2}
create_clock -period 10 -name default
source "./p00/solution1/directives.tcl"
csim_design -clean -setup
csynth_design
cosim_design
export_design -format ip_catalog
