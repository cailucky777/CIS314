#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void printInt(int x) {
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShot(short x) {
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
	printBytes((unsigned char *) &x, sizeof(long));
}

void printLongLong(long long x) {
	printBytes((unsigned char *) &x, sizeof(long long));
}

void printDouble(double x) {
	printBytes((unsigned char *) &x, sizeof(double));
}

int main(){
	printInt(12345);//39 30 00 00
	printFloat(12345);//00 e4 40 46
	printShot(12345);//39 30
	printLong(12345);//39 30 00 00 00 00 00 00
	printLongLong(12345);//39 30 00 00 00 00 00 00
	printDouble(12345);//00 00 00 00 80 1c c8 40
	//I found interger data and float-point have different byte pattern. Compare to float-point, double is more precise. 
	
}