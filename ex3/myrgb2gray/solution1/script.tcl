############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project myrgb2gray
set_top myrgb2gray
add_files myrgb2gray/test/IN_IMG.bmp
add_files myrgb2gray/src/myrgb2gray.cpp
add_files -tb myrgb2gray/test/test_rgb2gray.cpp
open_solution "solution1"
set_part {xq7z020cl400-1i} -tool vivado
create_clock -period 10 -name default
#source "./myrgb2gray/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
