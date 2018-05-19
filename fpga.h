#ifndef _FPGA_H
#define _FPGA_H

#define FPGA_ONCHIP_ADDR 0xc4000000

typedef struct __fpga_mem {
	uint8_t  command_field;
	uint64_t move_bits;
	uint64_t  piece_type :4,
						piece_square :6,
						:54;
	uint64_t bitboards[2];

} fpga_mem;

/*Buffer used for communicating with the FPGA, allocated in main.c*/
volatile fpga_mem *mem_buf;

#endif
