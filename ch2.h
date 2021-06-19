#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

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

//2.60
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned tmp1 = (~(0x000000ff << (i * 8))) & x;
    unsigned tmp2 = ((unsigned)b) << (i * 8);
    unsigned ans = tmp1 + tmp2;

    return ans;
}

//2.61
void exe_2_61()
{
    int x1 = 0xffffffff;
    cout << !~x1 << endl;

    int x2 = 0x00000000;
    cout << !x2 << endl;

    int x3 = 0x000f00ff;
    cout << !((~(x3 & 0xff)) & 0xff) << endl;

    int x4 = 0x000f0000;
    cout << !(x4 >> ((sizeof(int) - 1) << 3)) << endl;
}

//2.62
bool int_shifts_are_arithmetic()
{
    int i = -1;
    return (i >> (sizeof(int) << 3));
}

//2.63
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    unsigned mask = (0x00000001 << ((sizeof(int) << 3) - k)) - 1;
    return xsra & mask;
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    unsigned mask = 0x00000001 << ((sizeof(int) << 3) - k - 1);
    mask = mask & xsrl;
    mask = ~((mask << 1) - 1);
    return mask + xsrl;
}

//2.64
int any_odd_one(unsigned x)
{
    unsigned mask = 0xaaaaaaaa;
    return !!(mask & x);
}

//2.65
int odd_ones(unsigned x)
{
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 0x1;
}