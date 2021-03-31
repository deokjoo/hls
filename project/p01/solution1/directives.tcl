############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_interface -mode axis -register -register_mode both "ircam04" SRC_IMG_I
set_directive_interface -mode axis -register -register_mode both "ircam04" DST_IMG_O
set_directive_interface -mode m_axi -num_write_outstanding 32 -num_read_outstanding 32 -max_write_burst_length 16 -max_widen_bitwidth 16 -max_read_burst_length 16 -latency 100 -depth 80960 -bundle hist -offset slave "ircam04" SRC_HIS_I
set_directive_interface -mode m_axi -num_write_outstanding 32 -num_read_outstanding 32 -max_write_burst_length 16 -max_widen_bitwidth 16 -max_read_burst_length 16 -latency 100 -depth 80960 -bundle hist -offset slave "ircam04" DST_HIS_O
set_directive_interface -mode s_axilite "ircam04"
set_directive_pipeline -II 1 "ahe_proc00/c_loop"
set_directive_top -name ircam04 "ircam04"
set_directive_dataflow "ircam04"
