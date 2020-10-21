#include <stdio.h>

int oddBit(unsigned int x){
	
	unsigned int odd_Bit = x & 0xAAAAAAAA;//return only every odd-placed 1 in x.
	
	printf("%d\n",!!odd_Bit); // if exist 1 will return 1(true).
	return !!odd_Bit;
}

int main(){
	oddBit(0x1);
	oddBit(0x2);
	oddBit(0x3);
	oddBit(0x4);
	oddBit(0xFFFFFFFF);
	oddBit(0xAAAAAAAA);
	oddBit(0x55555555);
}