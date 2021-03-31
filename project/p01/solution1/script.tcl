############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project p01
set_top ircam04
add_files ../source/ahe.h
add_files ../source/ircam04.cpp -cflags "-I ../../Vitis_Libraries/vision/L1/include"
add_files ../source/ircam04.h
add_files -tb ../tb/tb_top.cpp -cflags "-I../../Vitis_Libraries/vision/L1/include"
open_solution "solution1" -flow_target vivado
set_part {xc7a200tsbv484-2}
create_clock -period 10 -name default
source "./p01/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level port
export_design -format ip_catalog
