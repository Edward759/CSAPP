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

//2.66
int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x >> 1) + (x && 1);
}

//2.67
//A. 32位机器未定义移位32次
//B
int bad_int_size_is_32_32()
{
    int set_msb = 1 << 31;
    int beyond_msb = 2 << 31;
    return set_msb && !beyond_msb;
}
//C
int bad_int_size_is_32_16()
{
    int a = 1 << 15;
    a <<= 15;
    int set_msb = a << 1;
    int beyond_msb = a << 2;
    return set_msb && !beyond_msb;
}

//2.68
int lower_one_mask(int n)
{
    return (0x1 << n) - 1;
}

//2.69
unsigned rotate_left(unsigned x, int n)
{
    int overflow = x >> (sizeof(unsigned) << 3) - n;
    x <<= n;
    return overflow + x;
}

//2.70
int fits_bits(int x,int n)
{
    unsigned ux=(unsigned)x;
    return !(ux >> n - 1);
}

//2.71
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
    int w = sizeof(packed_t);
    return int(word << ((w - bytenum - 1) << 3)) >> ((w - 1) << 3);
}

//2.72
void copy_int(int val, void* buf, int maxbytes)
{
    if(maxbytes>0&&maxbytes>=sizeof(val))
        memcpy(buf, (void *)&val, sizeof(val));
}

//2.73
int saturating_add(int x,int y)
{
    int sum = x + y;
    int mask = INT_MIN;
    int pos_of = !(x & mask) && !(y & mask) && (sum & mask);
    int neg_of = (x & mask) && (y & mask) && !(sum & mask);
    (pos_of && (sum = INT_MAX)) || (neg_of && (sum = INT_MIN));
    return sum;
}

//2.74
int tsub_ok(int x, int y)
{
    int sub = x - y;
    return !((x > 0 && y < 0 && sub < 0) || (x < 0 && y > 0 && sub > 0));
}