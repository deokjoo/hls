############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_interface -mode axis -register -register_mode both "ircam04" SRC_IMG_I
set_directive_interface -mode axis -register -register_mode both "ircam04" DST_IMG_O
set_directive_interface -mode m_axi -depth 80960 -latency 100 -offset slave -bundle hist -num_read_outstanding 32 -num_write_outstanding 32 -max_read_burst_length 16 -max_write_burst_length 16 -max_widen_bitwidth 16 "ircam04" SRC_HIS_I
set_directive_interface -mode m_axi -depth 80960 -latency 100 -offset slave -bundle hist -num_read_outstanding 32 -num_write_outstanding 32 -max_read_burst_length 16 -max_write_burst_length 16 -max_widen_bitwidth 16 "ircam04" DST_HIS_O
set_directive_interface -mode s_axilite "ircam04"
set_directive_pipeline -II 1 "ahe_proc00/c_loop"
set_directive_top -name ircam04 "ircam04"
set_directive_dataflow "ircam04"
set_directive_array_partition -type complete -dim 1 "ahe_filter" hist_line
set_directive_dependence -dependent false -type intra "ahe_filter/l_loop"
