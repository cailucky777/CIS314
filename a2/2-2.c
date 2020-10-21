#include <stdio.h>

unsigned int extract(unsigned int x, int i){
	signed int res = x;// change x into signed bit.
	unsigned int p1 = 24 - (i << 3);//to get correct bits to shift out. 
	res = res << p1;// first, shift to the left to move off useless bits and move the expect bits to the front.
	res = res >> 24;// then shift right to get the correct answer. 
	printf("0x%08X\n", res);
	return res;
}
int main() {
	
	extract(0x12345678, 0); //0x00000078
	extract(0xABCDEF00, 2); //0xFFFFFFCD
	
}