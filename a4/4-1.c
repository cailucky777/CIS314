//Luying Cai - A4
#include <stdio.h>
/*
loop:
	movq %rsi, %rcx     -> get the second argument b.
	movl $1, %eax       -> set mask equal to 1.
	movl $0, %edx       -> set third argument result equal to 0.
.L2:                    
	testq %rax, %rax    -> check %rax is negative,0 or positve number.
	je .L4              -> if equal to 0, jump to line 4.
	movq %rax, %r8      -> set return value as mask.
	andq %rdi, %r8      -> do and operation between a and mask.
	orq %r8, %rdx       -> do or operation between result and (a&mask).
	salq %cl, %rax      -> left shift mask by b bits.
	jmp .L2             -> continue for loop
.L4:
	movq %rdx, %rax     -> get the result value 
	ret                 -> return the result.
*/

long loop(long a, long b) {
	long result = 0;
	for (long mask = 1; mask != 0; mask <<= b) 
	{
		result |= (a & mask);
	}
	return result;
}


int main(){
	loop(1, 5);//1
	loop(2, 4);//0
	loop(3, 3);//1
	loop(4, 2);//4
	loop(5, 1);//5
}

