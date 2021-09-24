#!/bin/bash
cat SimTop.v axi_2x2.v axi_rw.v clint.v cpu.v csrfile.v defines.v ex_stage_alu.v ex_stage_bj.v ex_stage.v \
    excp_handler.v forward.v id_stage.v if_stage.v mem_stage.v regfile.v wb_stage.v > ysyx_210611.v