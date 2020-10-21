#include <stdio.h>
#include <stdlib.h>

void f(int x) {
	x = 30;
}

void g(int *xp) {
	*xp = 40;
}

int main() {
	// Allocate 8 bytes of memory (amount required to hold 2 ints).
	int *array = (int *)malloc(2 * sizeof(int));
	printf("1 [ %d %d ]\n", array[0], array[1]);

	array[0] = 10;
	array[1] = 20;

	printf("2 [ %d %d ]\n", array[0], array[1]);

	f(array[0]);

	printf("3 [ %d %d ]\n", array[0], array[1]);

	g(&array[1]);

	printf("4 [ %d %d ]\n", array[0], array[1]);

	free(array);

	printf("sizeof int %lu\n", sizeof(int));
	printf("sizeof int* %lu\n", sizeof(int*));

//	for (int i = 0; i < 100000; ++i) {
//		array[i] = 0;
//	}

	// basic gdb instructions:
	// 1) gcc -g -o malloc malloc.c
	// 2) gdb malloc
	// 3) run

	return 0;
}