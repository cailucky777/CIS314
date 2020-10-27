#include <stdio.h>

long fact(long x) {
	if (x <= 1) {
		return 1;
	}
	
	long px = x;
	long fx = fact(x - 1);
	return px * fx;
}
int main() {
	
}