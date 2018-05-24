module lab2(
	CLOCK_50,
	KEY,
	HPS_DDR3_ADDR,
	HPS_DDR3_BA,
	HPS_DDR3_CAS_N,
	HPS_DDR3_CKE,
	HPS_DDR3_CK_N,
	HPS_DDR3_CK_P,
	HPS_DDR3_CS_N,
	HPS_DDR3_DM,
	HPS_DDR3_DQ,
	HPS_DDR3_DQS_N,
	HPS_DDR3_DQS_P,
	HPS_DDR3_ODT,
	HPS_DDR3_RAS_N,
	HPS_DDR3_RESET_N,
	HPS_DDR3_RZQ,
	HPS_DDR3_WE_N,
	DRAM_CLK,
	DRAM_CKE,
	DRAM_ADDR,
	DRAM_BA,
	DRAM_CS_N,
	DRAM_CAS_N,
	DRAM_RAS_N,
	DRAM_WE_N,
	DRAM_DQ,
	DRAM_UDQM,
	DRAM_LDQM
);


 	input CLOCK_50;
	input [3:0] KEY;
	output [14:0] HPS_DDR3_ADDR;
	output [2:0] HPS_DDR3_BA;
	output HPS_DDR3_CAS_N,HPS_DDR3_CKE,HPS_DDR3_CK_N,HPS_DDR3_CK_P,HPS_DDR3_CS_N;
	output [3:0] HPS_DDR3_DM;
	inout [31:0] HPS_DDR3_DQ;
	inout [3:0] HPS_DDR3_DQS_N,HPS_DDR3_DQS_P;
	output HPS_DDR3_ODT,HPS_DDR3_RAS_N,HPS_DDR3_RESET_N;
	input HPS_DDR3_RZQ;
	output HPS_DDR3_WE_N;
	input DRAM_CLK;
	input DRAM_CKE;
	input [12:0] DRAM_ADDR;
	input [1:0] DRAM_BA;
	input DRAM_CS_N;
	input DRAM_CAS_N;
	input DRAM_RAS_N;
	input DRAM_WE_N;
	inout [15:0] DRAM_DQ;
	input DRAM_UDQM;
	input DRAM_LDQM;

    mysystem u0 (
	  .memory_mem_a       (HPS_DDR3_ADDR),       //      memory.mem_a
	  .memory_mem_ba      (HPS_DDR3_BA),      //            .mem_ba
	  .memory_mem_ck      (HPS_DDR3_CK_P),      //            .mem_ck
	  .memory_mem_ck_n    (HPS_DDR3_CK_N),    //            .mem_ck_n
	  .memory_mem_cke     (HPS_DDR3_CKE),     //            .mem_cke
	  .memory_mem_cs_n    (HPS_DDR3_CS_N),    //            .mem_cs_n
	  .memory_mem_ras_n   (HPS_DDR3_RAS_N),   //            .mem_ras_n
	  .memory_mem_cas_n   (HPS_DDR3_CAS_N),   //            .mem_cas_n
	  .memory_mem_we_n    (HPS_DDR3_WE_N),    //            .mem_we_n
	  .memory_mem_reset_n (HPS_DDR3_RESET_N), //            .mem_reset_n
	  .memory_mem_dq      (HPS_DDR3_DQ),      //            .mem_dq
	  .memory_mem_dqs     (HPS_DDR3_DQS_P),     //            .mem_dqs
	  .memory_mem_dqs_n   (HPS_DDR3_DQS_N),   //            .mem_dqs_n
	  .memory_mem_odt     (HPS_DDR3_ODT),     //            .mem_odt
	  .memory_mem_dm      (HPS_DDR3_DM),      //            .mem_dm
	  .memory_oct_rzqin   (HPS_DDR3_RZQ),   //            .oct_rzqin
        .sdram_wire_addr        (DRAM_ADDR),        //       sdram_wire.addr
        .sdram_wire_ba          (DRAM_BA),          //                 .ba
        .sdram_wire_cas_n       (DRAM_CAS_N),       //                 .cas_n
        .sdram_wire_cke         (DRAM_CKE),         //                 .cke
        .sdram_wire_cs_n        (DRAM_CS_N),        //                 .cs_n
        .sdram_wire_dq          (DRAM_DQ),          //                 .dq
        .sdram_wire_dqm         ({DRAM_UDQM,DRAM_LDQM}),         //                 .dqm
        .sdram_wire_ras_n       (DRAM_RAS_N),       //                 .ras_n
        .sdram_wire_we_n        (DRAM_WE_N),        //                 .we_n
	  .sdram_clk_clk          (DRAM_CLK),          //        sdram_clk.clk
	  .system_ref_clk_clk     (CLOCK_50),     //   system_ref_clk.clk
	  .system_ref_reset_reset (~KEY[0]), // system_ref_reset.reset
 
    );
	 
endmodule
