#include <stdio.h>

int le(float x, float y) {
unsigned int ux = *((unsigned int*) &x); // convert x raw bits 
unsigned int uy = *((unsigned int*) &y); // convert y raw bits 
unsigned int sx = ux >> 31; // extract sign bit of ux 
unsigned int sy = uy >> 31; // extract sign bit of uy
ux <<= 1; // drop sign bit of ux
uy <<= 1; // drop sign bit of uy

int both_pos = (sx == 0) & (sy == 0);// case in both x and y are positive.
int both_neg = (sx == 1) & (sy == 1);// case in both x and y are negative.
int both_zero = (ux == 0) & (uy == 0); // case in after drop sign bit, both x and y are zero.
int pos_neg = ((sx == 0) & (sy == 1)) | ((sy == 0) & (sx == 1)); // case in one is positive and one is negative. 

int res = (both_pos & (ux<=uy)) | (both_neg & (uy<=ux)) | both_zero | (pos_neg & (sx > sy));
printf("%d\n", res);
return res;

// TODO: return using sx, sy, ux, uy
}
int main() {
	le(0.0f, 0.0f); //1 
	le(-0.0f, 0.0f);//1 
	le(-1.0f, -1.0f); //1 
	le(1.0f, 1.0f); //1 
	le(-1.0f, 0.0f); //1 
	le(0.0f, 1.0f); //1 
	le(1.0f, 0.0f); //0 
	le(0.0f, -1.0f); //0 
	le(-1.0f, -2.0f); //0
}