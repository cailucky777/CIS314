#include <stdio.h>

int main()
{
    printf("0xABCDEF01 >> 2: %x\n", 0xABCDEF01 >> 2);
    printf("0xABCDEF01 << 2: %x\n", 0xABCDEF01 << 2);
    return 0;
}
// 3, the difference between 1 and 2 in my conclusion is the q1 is 0xABCDEF01 shift to the right 2 bits and add 2 zeros to the beginning of left side. q2 is shift to the left 2 bits and add 2 zeros to the end of right side. 