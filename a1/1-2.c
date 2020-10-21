#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b)
{
	unsigned int po_hold = 0xFF << (i << 3);//hold position for char b by FF.(i<<3 is 3*2^3)
	unsigned int replace = b << (i << 3);// hold position for char b.
	unsigned int p = ~ po_hold;//align the input byte by F. ->0x00FFFFFF
	unsigned int res = x & p;// leave position by 0. ->0x00345678
	res = res | replace;//combine.
	
	printf("0x%X\n", res);
	return res;
}

int main(){
	replace(0x12345678, 3, 0xAB);
	replace(0x12345678, 0, 0xAB);
}