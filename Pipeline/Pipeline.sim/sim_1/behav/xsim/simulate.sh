#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2023.1 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Fri May 31 13:32:05 CEST 2024
# SW Build 3865809 on Sun May  7 15:04:56 MDT 2023
#
# IP Build 3864474 on Sun May  7 20:36:21 MDT 2023
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim Test_Pipeline_behav -key {Behavioral:sim_1:Functional:Test_Pipeline} -tclbatch Test_Pipeline.tcl -view /home/barnavon/Bureau/4A/Projet_Sys_Info/Projet-Systeme-Informatique/Pipeline/Pipeline.srcs/sim_1/imports/ALU/Test_Pipeline_behav.wcfg -log simulate.log"
xsim Test_Pipeline_behav -key {Behavioral:sim_1:Functional:Test_Pipeline} -tclbatch Test_Pipeline.tcl -view /home/barnavon/Bureau/4A/Projet_Sys_Info/Projet-Systeme-Informatique/Pipeline/Pipeline.srcs/sim_1/imports/ALU/Test_Pipeline_behav.wcfg -log simulate.log

