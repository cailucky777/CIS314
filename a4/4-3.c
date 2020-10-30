#include <stdio.h>

long fact(long x) {
	if (x <= 1) { //cmpq	$1, %rdi 
		return 1; //jle .L3
	}
	
	long px = x; // use push operation to save x value into px if x greater than 1.
	long fx = fact(x - 1);// use pop operation to do the recursive call and the value save in fx.
	return px * fx; // use pop operation to multiple each x grater than 1 and return the result.
}
int main() {
	printf("%ld\n", fact(1));
	printf("%ld\n", fact(2));
	printf("%ld\n", fact(3));

	return 0;

}