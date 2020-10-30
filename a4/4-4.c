#include <stdio.h>
#define N 4
typedef long array_t[N][N];
/* 
void transpose(array_t a) {
	for (long i = 0; i < N; ++i) {
		for (long j = 0; j < i; ++j) {
			long t1 = a[i][j];
			long t2 = a[j][i];
			a[i][j] = t2;
			a[j][i] = t1;
		}
	}
}
*/

/* .L3: //start from line 3
		movq (%rax), %rcx  // take the value in rax,and dereference it. get the rax value at that memory and loaded into rcx. 
		movq (%rdx), %rsi  // take the value in rdx and dereference it. Get the rdx value at that memory and loaded into rsi.
		movq %rsi, (%rax)  // swap, take the value in rsi, those eight bytes go right back to memory starting at the pointer rax. (take the value rsi float into memory at rax.)
		movq %rcx, (%rdx)  // swap, dereferenve the pointer rdx and load rcx into memory at that location.
		addq $8, %rax      // increment i (from book)
		addq $32, %rdx     // increment j
		cmpq %r9, %rax     // compare j and i
		jne .L3           // if not zero, go to line 3.(from lecture)
*/


void new_transpose(array_t a) {
	for (long i = 0; i < N; ++i){
		long *rp = &a[i][0];//points to elements in row.
		long *cp = &a[0][i];//points to elements in column.
		for (long j = 0; j < i; ++j){
			long t1 = *rp; //get the value store in t1.
			long t2 = *cp; //get the value store in t2.
			*rp = t2; //swap 
			*cp = t1; //swap
			rp++;//move rp to the mext column.
			cp += N;//move cp to next row.
		}
	}
}


int main(int argc, char *argv[]) {
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	new_transpose(a); // call function.
	printf("{"); //print outside {}
	for (long i = 0; i < N; i++) {
		printf("{");
		for (long j = 0; j < N; j++) {
			printf("%ld", a[i][j]);
			if(j != N - 1) {
				printf(", ");
			}
			else if(i != N-1 & j == N - 1) {
				printf("}, ");	       
			}
			else {
				printf("}");
			}
		}
	}
	printf("}\n");
	return 0;

}