#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y)
{
	unsigned int res = (x & 0xFFFFFF00) | (y & 0x000000FF);
	//using bitwise or to combine used bit mask to isolate bytes 3 through 1 from x and another bit mask isolate byte 0 from y to get result.
	printf("0x%X\n", res);
	return res;	
}

int main() {
	combine(0x12345678, 0xABCDEF00);
	combine(0xABCDEF00, 0X12345678);

}