#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void){
	//volatile int * hex3 = (int *) 0xFF200000; // hex5_hex0 address
	//volatile int * buttonptr = (int *) 0xFF200020; // pushbutton address
	volatile int * on_chip = (int*) 0xC4000000;
	
	//int button_value;
	//int quit = 0;
	//int32_t x = 0;
	int x = 0;
	//int valid = 1;

	printf("Enter a 32-bit number\n");
	scanf("%d", &x);
	*on_chip = x;
	printf("x: %d\n", x);
	printf("on_chip: %d\n", *on_chip);
	//while (1)
	//{
	//button_value = *buttonptr;
	//*on_chip = 124;
	//printf("Enter a 32-bit number\n");
	//scanf("%d", &x);
	//*on_chip = x;
	//*(hex3) = 7;
//printf("1\n");
	//printf("x: %d\n", x);
	//printf("on_chip: %d\n", *on_chip);
	//printf("button value: %d \n", button_value);
	//printf("Enter the 32-bit integer\n");
		//scanf("%s", numStr);

		//valid = scanf("%" SCNd32, &x);
		//if(valid < 0){
			//continue;
			//printf("Enter the 32-bit integer\n");
			//scanf("%s", numStr);
			//continue;
			//valid = scanf("%" SCNd32, &x);
		//} else	printf("%" PRId32 "\n", x);

/*
		printf("Do you want to quit?\n");
		scanf("%s", quitStr);
		if((quitStr[0] == 'y') || (quitStr[0] == 'Y')){
			return 0;
		}
*/
		//*(hex5) = x;
	//}
/*
	static inline unsigned int getCycles ()
{
 unsigned int cycleCount;
 // Read CCNT register
 asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(cycleCount));
 return cycleCount;
}
static inline void initCounters ()
{
 // Enable user access to performance counter
 asm volatile ("MCR p15, 0, %0, C9, C14, 0\t\n" :: "r"(1));
 // Reset all counters to zero
 int MCRP15ResetAll = 23;
 asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(MCRP15ResetAll));
 // Enable all counters:
 asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));
 // Disable counter interrupts
 asm volatile ("MCR p15, 0, %0, C9, C14, 2\t\n" :: "r"(0x8000000f));
 // Clear overflows:
 asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}
int main(void)
{
int i = 0;
int fakeCounter = 0;
initCounters ();

unsigned int time = getCycles();
for (i = 0; i < 20000; i++)
fakeCounter = fakeCounter + 1;
time = getCycles() - time;
printf ("Elapsed Time: %d cycles\n", time);
time = getCycles();
for (i = 0; i < 200000; i++)
fakeCounter = fakeCounter + 1;
time = getCycles() - time;
printf ("Elapsed Time: %d cycles\n", time);
}

	/*
	int quit = 0;
	int valid = 1;
	char quitStr[100];
	//char *numStr;
	int32_t x = 0; 
	while(quit == 0){
		printf("Enter the 32-bit integer\n");
		//scanf("%s", numStr);

		valid = scanf("%" SCNd32, &x);
		if(valid < 0){
			//continue;
			//printf("Enter the 32-bit integer\n");
			//scanf("%s", numStr);
			continue;
			//valid = scanf("%" SCNd32, &x);
		} else	printf("%d\n", x);


		printf("Do you want to quit?\n");
		scanf("%s", quitStr);
		if((quitStr[0] == 'y') || (quitStr[0] == 'Y')){
			return 0;
		}
	}
	return 0;
	*/
}


/*
int main(void)
{
volatile int * led = (int *) 0xFF200040; // red LED address
volatile int * switchptr = (int *) 0xFF200030; // SW slider switch address
int switch_value;
while (1)
{
switch_value = *(switchptr);
*(led) = switch_value;
}
}

void Update_HEX_Display( int buffer )
{
volatile int * HEX3_HEX0_ptr = (int *) HEX3_HEX0_BASE;
volatile int * HEX7_HEX4_ptr = (int *) HEX7_HEX4_BASE;
int shift_buffer, nibble;
char code;
int i;
shift_buffer = buffer;
for ( i = 0; i < 8; ++i )
{
nibble = shift_buffer & 0x0000000F; // character is in rightmost nibble
code = seven_seg_decode_table[nibble];
hex_segments[i] = code;
shift_buffer = shift_buffer >> 4;
}
*(HEX3_HEX0_ptr) = *(int *) hex_segments; // drive the hex displays
*(HEX7_HEX4_ptr) = *(int *) (hex_segments+4); // drive the hex displays
return;
}

int main(void)
{
*/
/* Declare volatile pointers to I/O registers (volatile means that IO load and store
instructions (e.g., ldwio, stwio) will be used to access these pointer locations) */
/*
volatile int * red_LED_ptr = (int *) 0x10000000; // red LED address
volatile int * green_LED_ptr = (int *) 0x10000010; // green LED address
volatile int * HEX3_HEX0_ptr = (int *) 0x10000020; // HEX3_HEX0 address
volatile int * HEX7_HEX4_ptr = (int *) 0x10000030; // HEX7_HEX4 address
volatile int * SW_switch_ptr = (int *) 0x10000040; // SW slider switch address
volatile int * KEY_ptr = (int *) 0x10000050; // pushbutton KEY address
int HEX_bits = 0x0000000F; // pattern for HEX displays
int SW_value, KEY_value;
volatile int delay_count; // volatile so C compile does not remove loop
while(1)
{
SW_value = *(SW_switch_ptr); // read the SW slider switch values
*(red_LED_ptr) = SW_value; // light up the red LEDs
KEY_value = *(KEY_ptr); // read the pushbutton KEY values
*(green_LED_ptr) = KEY_value; // light up the green LEDs
if (KEY_value != 0) // check if any KEY was pressed
{
HEX_bits = SW_value; // set pattern using SW values
while (*KEY_ptr); // wait for pushbutton KEY release
}
*(HEX3_HEX0_ptr) = HEX_bits; // display pattern on HEX3 ... HEX0
*(HEX7_HEX4_ptr) = HEX_bits; // display pattern on HEX7 ... HEX4

if (HEX_bits & 0x80000000) *//* rotate the pattern shown on the HEX displays */
/*
HEX_bits = (HEX_bits << 1) | 1;
else
HEX_bits = HEX_bits << 1;
for (delay_count = 100000; delay_count != 0; −−delay_count); // delay loop
} // end while
}
*/
