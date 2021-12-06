
//--Sun Jiru, Nanjing Univeristy--

`include "defines.v"

module csrfile(
  input wire                              clk,
  input wire                              rst,
  
  input wire                              csr_wr_clk,
  
  // id stage
  input wire                              csr_rd_ena,
  input wire [11 : 0]                     csr_rd_addr,
  output wire [`REG_BUS]                  csr_rd_data,
  
  // wb stage
  input wire                              csr_wr_ena,
  input wire [11 : 0]                     csr_wr_addr,
  input wire [`REG_BUS]                   csr_wr_data,
  
  // exception
  output wire [`EXCP_RD_WIDTH-1:0]        csr_excp_rd_bus,
  input wire [`EXCP_WR_WIDTH-1:0]         csr_excp_wr_bus,
  
  // exception read and write
  input wire                              excp_enter,
  input wire                              excp_exit,
  
  // difftest bus
  output wire [`CSR_TO_EX_DIFF_WIDTH-1:0] csr_to_ex_diffbus
  );
  
  wire [`REG_BUS] mip_wr_data, mstatus_wr_data, mepc_wr_data,
                  mcause_wr_data, mtval_wr_data;
  assign {
    mip_wr_data,
    mcause_wr_data,
    mepc_wr_data,
    mtval_wr_data,
    mstatus_wr_data
  } = csr_excp_wr_bus;

  assign csr_excp_rd_bus = {
    csr_mstatus,
    csr_mtvec,
    csr_mepc,
    csr_mip,
    csr_mie
  };
  
  wire excp_enter_wr = excp_enter && csr_wr_clk;
  wire excp_exit_wr  = excp_exit  && csr_wr_clk;
  wire excp_wr = (excp_enter || excp_exit) && csr_wr_clk;

  // 0x300 Machine Status Register
  wire sel_rd_mstatus = (csr_rd_addr == 12'h300);
  wire sel_wr_mstatus = (csr_wr_addr == 12'h300);
  wire mstatus_rd_ena = sel_rd_mstatus && csr_rd_ena;
  wire mstatus_wr_ena = sel_wr_mstatus && csr_wr_ena && csr_wr_clk;
  wire [`REG_BUS] mstatus_wr_data_full = {
    (mstatus_wr_data[14:13] == 2'b11) || (mstatus_wr_data[16:15] == 2'b11),
    mstatus_wr_data[30:0]
  };
  wire [`REG_BUS] csr_wr_data_full = {
    (csr_wr_data[14:13] == 2'b11) || (csr_wr_data[16:15] == 2'b11),
    csr_wr_data[30:0]
  };

  reg [`REG_BUS] csr_mstatus;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mstatus <= 32'h1880;
    end
    else if (excp_wr) begin
      csr_mstatus <= 32'h8001F888 & mstatus_wr_data_full;
    end
    else if (mstatus_wr_ena) begin
      csr_mstatus <= 32'h8001F888 & csr_wr_data_full;
    end
  end

  wire [`REG_BUS] mstatus_rd_data = (
    excp_wr        ? mstatus_wr_data_full :
    mstatus_wr_ena ? csr_wr_data_full :
                     csr_mstatus
  );
  
  // 0x301 Machine ISA Register
  wire sel_misa = (csr_rd_addr == 12'h301);
  wire misa_rd_ena = sel_misa & csr_rd_ena;
  wire [`REG_BUS] csr_misa = {
    2'b10
    ,4'b0 //WIRI
    ,1'b0 //              25 Z Reserved
    ,1'b0 //              24 Y Reserved
    ,1'b0 //              23 X Non-standard extensions present
    ,1'b0 //              22 W Reserved
    ,1'b0 //              21 V Tentatively reserved for Vector extension 20 U User mode implemented
    ,1'b0 //              20 U User mode implemented
    ,1'b0 //              19 T Tentatively reserved for Transactional Memory extension
    ,1'b0 //              18 S Supervisor mode implemented
    ,1'b0 //              17 R Reserved
    ,1'b0 //              16 Q Quad-precision floating-point extension
    ,1'b0 //              15 P Tentatively reserved for Packed-SIMD extension
    ,1'b0 //              14 O Reserved
    ,1'b0 //              13 N User-level interrupts supported
    ,1'b0 //              12 M Integer Multiply/Divide extension
    ,1'b0 //              11 L Tentatively reserved for Decimal Floating-Point extension
    ,1'b0 //              10 K Reserved
    ,1'b0 //              9 J Reserved
    ,1'b1 //              8 I RV32I/64I/128I base ISA
    ,1'b0 //              7 H Hypervisor mode implemented
    ,1'b0 //              6 G Additional standard extensions present
    ,1'b0 //              5 F Single-precision floating-point extension
    ,1'b0 //              4 E RV32E base ISA
    ,1'b0 //              3 D Double-precision floating-point extension
    ,1'b0 //              2 C Compressed extension
    ,1'b0 //              1 B Tentatively reserved for Bit operations extension
    ,1'b0 //              0 A Atomic extension
  };

  wire [`REG_BUS] misa_rd_data = csr_misa;

  // 0x304 Machine Interrupt Enable Register
  wire sel_rd_mie = csr_rd_addr == 12'h304;
  wire sel_wr_mie = csr_wr_addr == 12'h304;
  wire mie_rd_ena = csr_rd_ena && sel_rd_mie;
  wire mie_wr_ena = csr_wr_ena && sel_wr_mie && csr_wr_clk;
  reg [`REG_BUS] csr_mie;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mie <= 32'h888;  // only for machine mode
    end
    else if (mie_wr_ena) begin
      csr_mie <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mie_rd_data = mie_wr_ena ? csr_wr_data : csr_mie;

  // 0x305 Machine Trap-Vector Base-Address Register
  wire sel_rd_mtvec = (csr_rd_addr == 12'h305);
  wire sel_wr_mtvec = (csr_wr_addr == 12'h305);
  wire mtvec_rd_ena = csr_rd_ena && sel_rd_mtvec;
  wire mtvec_wr_ena = csr_wr_ena && sel_wr_mtvec && csr_wr_clk;
  reg [`REG_BUS] csr_mtvec;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mtvec <= `ZERO_WORD;
    end
    else if (mtvec_wr_ena) begin
      csr_mtvec <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mtvec_rd_data = mtvec_wr_ena ? csr_wr_data : csr_mtvec;
  
  // 0x340 Machine Scratch Register
  wire sel_rd_mscratch = (csr_rd_addr == 12'h340);
  wire sel_wr_mscratch = (csr_wr_addr == 12'h340);
  wire mscratch_rd_ena = csr_rd_ena && sel_rd_mscratch;
  wire mscratch_wr_ena = csr_wr_ena && sel_wr_mscratch && csr_wr_clk;
  reg [`REG_BUS] csr_mscratch;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mscratch <= `ZERO_WORD;
    end
    else if (mscratch_wr_ena) begin
      csr_mscratch <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mscratch_rd_data = mscratch_wr_ena ? csr_wr_data : csr_mscratch;

  // 0x341 Machine Exception Program Counter
  wire sel_rd_mepc = (csr_rd_addr == 12'h341);
  wire sel_wr_mepc = (csr_wr_addr == 12'h341);
  wire mepc_rd_ena = csr_rd_ena && sel_rd_mepc;
  wire mepc_wr_ena = csr_wr_ena && sel_wr_mepc && csr_wr_clk;
  reg [`REG_BUS] csr_mepc;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mepc <= `ZERO_WORD;
    end
    else if (excp_enter_wr) begin
      csr_mepc <=  mepc_wr_data;
    end
    else if (mepc_wr_ena) begin
      csr_mepc <= csr_wr_data;
    end
  end
  
  wire [`REG_BUS] mepc_rd_data = (
    excp_enter  ? mepc_wr_data :
    mepc_wr_ena ? csr_wr_data :
                  csr_mepc
  );

  // 0x342 Machine Cause Register
  wire sel_rd_mcause = (csr_rd_addr == 12'h342);
  wire sel_wr_mcause = (csr_wr_addr == 12'h342);
  wire mcause_rd_ena = csr_rd_ena && sel_rd_mcause;
  wire mcause_wr_ena = csr_wr_ena && sel_wr_mcause && csr_wr_clk;
  reg [`REG_BUS] csr_mcause;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mcause <= `ZERO_WORD;
    end
    else if (excp_enter_wr) begin
      csr_mcause <=  mcause_wr_data;
    end
    else if (mcause_wr_ena) begin
      csr_mcause <= csr_wr_data;
    end
  end
  
  wire [`REG_BUS] mcause_rd_data = (
    excp_enter    ? mcause_wr_data :
    mcause_wr_ena ? csr_wr_data :
                    csr_mcause
  );
  
  // 0x343 Machine Trap Value Register
  wire sel_rd_mtval = (csr_rd_addr == 12'h343);
  wire sel_wr_mtval = (csr_wr_addr == 12'h343);
  wire mtval_rd_ena = csr_rd_ena && sel_rd_mtval;
  wire mtval_wr_ena = csr_wr_ena && sel_wr_mtval && csr_wr_clk;
  reg [`REG_BUS] csr_mtval;
  
  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mtval <= `ZERO_WORD;
    end
    else if (excp_enter_wr) begin
      csr_mtval <= mtval_wr_data;
    end
    else if (mtval_wr_ena) begin
      csr_mtval <= csr_wr_data;
    end
  end

  wire [`REG_BUS] mtval_rd_data = (
    excp_enter   ? mtval_wr_data :
    mtval_wr_ena ? csr_wr_data :
                   csr_mtval
  );

  // 0x344 Machine Interrupt Pending Register
  wire sel_rd_mip = (csr_rd_addr == 12'h344);
  wire sel_wr_mip = (csr_wr_addr == 12'h344);
  wire mip_rd_ena = csr_rd_ena && sel_rd_mip;
  wire mip_wr_ena = csr_wr_ena && sel_wr_mip && csr_wr_clk;
  reg [`REG_BUS] csr_mip;
  /*
  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mip <= 64'h80;
    end
    else if (mip_wr_ena) begin
      csr_mip <= csr_wr_data;
    end
    // TODO: when interruption pending, mip should flip corresponding bit
  end
  */
  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mip <= 32'h80;
    end
    else begin
      csr_mip <= mip_wr_data;
    end
  end

  wire [`REG_BUS] mip_rd_data = mip_wr_data;

  // 0xB00 Cycle Counter
  wire sel_rd_mcycle = (csr_rd_addr == 12'hb00);
  wire sel_wr_mcycle = (csr_wr_addr == 12'hb00);
  wire mcycle_rd_ena = csr_rd_ena && sel_rd_mcycle;
  wire mcycle_wr_ena = csr_wr_ena && sel_wr_mcycle && csr_wr_clk;
  reg [`REG_BUS] csr_mcycle;

  always @(posedge clk) begin
    if (rst == 1'b1) begin
      csr_mcycle <= `ZERO_WORD;
    end
    else if (mcycle_wr_ena) begin
      csr_mcycle <= csr_wr_data;
    end
    else begin
      csr_mcycle <= csr_mcycle + 32'b1;
    end
  end

  wire [`REG_BUS] mcycle_rd_data = mcycle_wr_ena ? csr_wr_data : (csr_mcycle + 32'b1);

  // 0xF11 Machine Vendor ID Register
  wire sel_mvendorid = (csr_rd_addr == 12'hf11);
  wire mvendorid_rd_ena = (csr_rd_ena & sel_mvendorid);
  wire [`REG_BUS] csr_mvendorid = `ZERO_WORD;
  wire [`REG_BUS] mvendorid_rd_data = csr_mvendorid;
  
  // 0xF12 Machine Architecture ID Register
  wire sel_marchid= (csr_rd_addr == 12'hf12);
  wire marchid_rd_ena = (csr_rd_ena & sel_marchid);
  wire [`REG_BUS] csr_marchid = `ZERO_WORD;
  wire [`REG_BUS] marchid_rd_data = csr_marchid;
  
  // 0xF13 Machine Implementation ID Register
  wire sel_mimpid= (csr_rd_addr == 12'hf13);
  wire mimpid_rd_ena = (csr_rd_ena & sel_mimpid);
  wire [`REG_BUS] csr_mimpid = `ZERO_WORD;
  wire [`REG_BUS] mimpid_rd_data = csr_mimpid;

  // 0xF14 Hart ID Register
  wire sel_mhartid= (csr_rd_addr == 12'hf14);
  wire mhartid_rd_ena = (csr_rd_ena & sel_mhartid);
  wire [`REG_BUS] csr_mhartid = `ZERO_WORD;
  wire [`REG_BUS] mhartid_rd_data = csr_mhartid;

  assign csr_rd_data = {32{~rst}} & (
      ({32{mstatus_rd_ena}}   & mstatus_rd_data)
    | ({32{misa_rd_ena}}      & misa_rd_data)
    | ({32{mie_rd_ena}}       & mie_rd_data)
    | ({32{mtvec_rd_ena}}     & mtvec_rd_data)
    | ({32{mscratch_rd_ena}}  & mscratch_rd_data)
    | ({32{mepc_rd_ena}}      & mepc_rd_data)
    | ({32{mcause_rd_ena}}    & mcause_rd_data)
    | ({32{mtval_rd_ena}}     & mtval_rd_data)
    | ({32{mip_rd_ena}}       & mip_rd_data)
    | ({32{mcycle_rd_ena}}    & mcycle_rd_data)
    | ({32{mvendorid_rd_ena}} & mvendorid_rd_data)
    | ({32{marchid_rd_ena}}   & marchid_rd_data)
    | ({32{mimpid_rd_ena}}    & mimpid_rd_data)
    | ({32{mhartid_rd_ena}}   & mhartid_rd_data)
  );

  assign csr_to_ex_diffbus = {
    mstatus_rd_data, mepc_rd_data, mtval_rd_data, mtvec_rd_data,
    mcause_rd_data, mip_rd_data, mie_rd_data, mscratch_rd_data
  };

endmodule