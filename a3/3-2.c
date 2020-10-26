//Luying Cai A3-2

#include <stdio.h>

long f(long x, long y, long z)
{	// Because x is in %rdi, y is in %rsi, z is in %rdx, and that %rax is used to hold the return value.
	// for convienve, 
	long rdi = x; //Argument x
	long rsi = y; //Argument y
	long rdx = z; //Argument z
	long rax; // return value
	
	//addq %rsi, %rdx, add rsi to rdx.
	rdx = rsi + rdx;
	//imulq %rdx, %rdi, multiple rdx to rdi.
	rdi = rdx * rdi;
	//salq $63, %rdx , shift rdx to left 63 bits.
	rdx = rdx << 63;
	//sarq $63, %rdx, shift rdx to right 63 bits.
	rdx = rdx >> 63;
	//movq %rdi, %rax, assign rdi value to rax.
	rax = rdi;
	//xorq %rdx, %rax, do xor. 
	rax = rax ^ rdx;
	
	return rax; //return value. 
}



int main() {
	printf("%ld\n", f(1, 2, 4)); //6
	printf("%ld\n", f(3, 5, 7)); //36
	printf("%ld\n", f(10, 20, 30)); //500
	return 0;
}


