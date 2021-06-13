#include <stdio.h>

typedef unsigned char *byte_pointer;

//exe 2.55 2.56 2.57
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len;i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void*));
}

void show_short(short x)
{
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_double(double x)
{
    show_bytes((byte_pointer)&x, sizeof(double));
}

//2.58
bool is_little_endian()
{
    int x = 1;
    unsigned char y = (unsigned char)x;

    return y;
}

void exe_2_59(int x, int y)
{
    int ans = (x & 0xff) + (y & 0xffffff00);
    show_int(x);
    show_int(y);
    show_int(ans);
}