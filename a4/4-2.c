#include <stdio.h>
/*
int sum(int from, int to){
	int result = 0;
	do {
		result += from;
		++from;
	} while (from <= to);
	return result;
}
*/
// a, Convert the above C code into a goto version by replacing the loop with a goto statement and label.
/*
int sum(int from, int to){
	int result = 0;

	loop:
		{
			result += from;
		}
	++from;
	if(from <= to)
		goto loop;
	done:
		return result;
}
*/

//b.  Implement your code from part a above in x86-64. Use the following as a framework:
	long sum(long from, long to) {
		// Declar and initialize result var – *do not modify*.
		long result = 0;
		// Ensure that argument *from* is in %rdi,
		// argument *to* is in %rsi, *result* is in %rax - *do not
		// modify*.
		__asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
		__asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
		__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));
		// Your x86-64 code goes below - comment each instruction...
		__asm__(
			// TODO - Replace the two lines below with add, compare,
			// jump instructions, labels, etc as necessary to implement
			// the loop.
			"loop:"
			"addq %rdi, %rax;" // add from to the result.
			"addq $1, %rdi;" // increase from.
				"cmpq %rsi, %rdi;" //check if from less or equal than to.
			"jie .loop" //if less than and equal than to, go back to loop.
			"movq %rax, %rbx;" // save result.
			"movq %rbx, %rax;" // return result.
		);
	// Ensure that *result* is in %rax for return - *do not modify*.
	__asm__ ("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	return result;

int main() {
	printf("%d\n",sum(1, 6));// 21
	printf("%d\n",sum(3, 5));//12
	printf("%d\n",sum(5, 3));//5
}