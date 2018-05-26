#ifndef _FPGA_H
#define _FPGA_H

#define FPGA_ONCHIP_ADDR 0xff200000

typedef struct __fpga_mem {
	uint64_t  command_field:8,
						piece_type :4,
						piece_square :6,
						:46;
	uint64_t occupying_piece_color;
	uint64_t is_occupied_wires;
	uint64_t move_bits;

} fpga_mem;

/*Buffer used for communicating with the FPGA, allocated in main.c*/
volatile fpga_mem *mem_buf;
volatile void *mem_ptr;

#endif
