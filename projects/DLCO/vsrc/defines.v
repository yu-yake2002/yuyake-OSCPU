
//--Sun Jiru, Nanjing University--

`timescale 1ns / 1ps

`define RISCV_PRIV_MODE_U   0
`define RISCV_PRIV_MODE_S   1
`define RISCV_PRIV_MODE_M   3

`define ZERO_WORD  32'h00000000
`define PC_START   32'h80000000
`define REG_BUS    31 : 0
`define INST_BUS   31 : 0

`define ID_TO_EX_WIDTH        210
`define EX_TO_MEM_WIDTH       124
`define MEM_TO_WB_WIDTH       114

`define BJ_CTRL_WIDTH         34
`define MEM_FORWARD_WIDTH     41
`define WB_FORWARD_WIDTH      73

`define ID_TO_EX_DIFF_WIDTH   1
`define CSR_TO_EX_DIFF_WIDTH  256
`define EX_TO_MEM_DIFF_WIDTH  64+`CSR_TO_EX_DIFF_WIDTH+`ID_TO_EX_DIFF_WIDTH
`define MEM_TO_WB_DIFF_WIDTH  70+`EX_TO_MEM_DIFF_WIDTH
`define WB_DIFFTEST_WIDTH     65+`MEM_TO_WB_DIFF_WIDTH


`define EXCP_RD_WIDTH       160
`define EXCP_WR_WIDTH       160

`define AXI_ADDR_WIDTH      32
`define AXI_DATA_WIDTH      32
`define AXI_ID_WIDTH        4
`define AXI_USER_WIDTH      1

`define SIZE_B              2'b00
`define SIZE_H              2'b01
`define SIZE_W              2'b10

`define REQ_READ            1'b0
`define REQ_WRITE           1'b1

`define ALU_ADD    0
`define ALU_SUB    1
`define ALU_SLT    2
`define ALU_SLTU   3
`define ALU_XOR    4
`define ALU_OR     5
`define ALU_AND    6
`define ALU_SLL    7
`define ALU_SRL    8
`define ALU_SRA    9
`define ALU_ANDN   10
`define ALU_WRI    11
`define ALU_BUS    11 : 0

`define BJ_BEQ  0
`define BJ_BNE  1
`define BJ_BLT  2
`define BJ_BGE  3
`define BJ_BLTU 4
`define BJ_BGEU 5
`define BJ_JALR 6
`define BJ_JAL  7
`define BJ_HALT 8
`define BJ_BUS  8 : 0

`define LOAD_LB  0
`define LOAD_LH  1
`define LOAD_LW  2
`define LOAD_LBU 3
`define LOAD_LHU 4
`define LOAD_BUS 4 : 0

`define SAVE_SB  0
`define SAVE_SH  1
`define SAVE_SW  2
`define SAVE_BUS 2 : 0

`define INST_I_LOAD        0
`define INST_I_FENCE       1
`define INST_I_ARITH_DWORD 2
`define INST_U_AUIPC       3
`define INST_I_ARITH_WORD  4
`define INST_S             5
`define INST_R_DWORD       6
`define INST_U_LUI         7
`define INST_R_WORD        8
`define INST_B             9
`define INST_I_JALR        10
`define INST_J             11
`define INST_I_EXP         12
`define INST_I_CSR_IMM     13
`define INST_I_CSR_REG     14
`define INST_PUTCH         15
`define OP_BUS             15 : 0

`define CSR_MISA       0
`define CSR_MCYCLE     1
`define CSR_MVENDORID  2
`define CSR_MARCHID    3
`define CSR_MIMPID     4
`define CSR_MHARTID    5
`define CSR_BUS        5 : 0

`define EXE_TO_REG   0
`define MEM_TO_REG   1
`define CSR_TO_REG   2
`define REG_CTRL_BUS 2 : 0

`define SOFT_ITRP  3
`define TIMER_ITRP 7
`define EXTER_ITRP 11
`define ITRP_BUS   11 : 0

`define EXCP_INST_MISAL 0
`define EXCP_INST_ACC   1
`define EXCP_ILG_INST   2
`define EXCP_BRK_PT     3
`define EXCP_LOAD_MISAL 4
`define EXCP_LOAD_ACC   5
`define EXCP_STOR_MISAL 6
`define EXCP_STOR_ACC   7
`define EXCP_ECALL_M    11
`define EXCP_INST_PAGE  12
`define EXCP_LOAD_PAGE  13
`define EXCP_STOR_PAGE  15
`define EXCP_BUS        15 : 0
