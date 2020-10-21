#include <stdio.h>


void print_binary(unsigned int x)
{
    while (x)
    {
        if (x & 1)
            fprintf(stderr,"1");
        else
            fprintf(stderr,"0");
        x >>= 1;
    }
}

void logical(int a, int b)
{
    printf("a == b %d\n", a == b);
    printf("a != b %d\n", a != b);
    printf("a && b %d\n", a && b);
    printf("a || b %d\n", a || b);
}

void bitwise(int a, int b)
{
    fprintf(stderr,"Bitwise Operations with (%u,%u)\n",a,b);
    fprintf(stderr,"Binary representations: (0b");
    print_binary(a);
    fprintf(stderr, ",");
    print_binary(b);
    fprintf(stderr, ")\n");
    unsigned int q = a & b;
    fprintf(stderr, "bitwise_and_&: %u\n", q);
    fprintf(stderr, "Binary representations: ");
    print_binary(q);
    q = a | b;
    fprintf(stderr, "\nBitwise_or_|: %u\n", q);
    fprintf(stderr, "Binary representations: ");
    print_binary(q);
    q = a ^ b;
    fprintf(stderr, "\nBitwise_xor_^: %u\n", q);
    fprintf(stderr, "Binary representations: ");
    print_binary(q);
    fprintf(stderr, "\n");
}



int main()
{
    logical(0,1);
    bitwise(1,1);
    bitwise(0b00101010,0b00101011);
    return 0;
}
