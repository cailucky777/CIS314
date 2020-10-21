#include <stdio.h>

int mask(int n){
	unsigned int res = 0xFFFFFFFF >> (32 - n);// to get the right position(32-n is remain no bits) to mask.
	
	printf("0x%X\n", res);
	return res;
}


int main() {
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(31);
}