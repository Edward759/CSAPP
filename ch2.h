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
//A. 32????????????????????????32???
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

//2.75
unsigned unsigned_high_prob(unsigned x, unsigned y)
{
    //TODO
}

//2.76
void *calloc(size_t nmemb, size_t size)
{
    //TODO
}

//2.77
void exe_2_77()
{
    int x = 2;
    int ans1 = x * 17;
    int ans2 = (x << 4) + x;
    cout << (ans1 == ans2) << endl;

    ans1 = x * -7;
    ans2 = x - (x << 3);
    cout << (ans1 == ans2) << endl;

    ans1 = x * 60;
    ans2 = (x << 6) - (x << 2);
    cout << (ans1 == ans2) << endl;

    ans1 = x * -112;
    ans2 = (x << 4) - (x << 7);
}

//2.78
int divide_power2(int x, int k)
{
    int sig = x & INT_MIN;
    (sig && (x = x + (1 << k) - 1));
    return x >> k;
}

//2.79
int mul3div4(int x)
{
    x = (x << 1) + x;
    return divide_power2(x, 2);
}

//2.80
int threefourths(int x)
{
    //TODO
}

//2.81
void exe_2_81(int k, int j)
{
    int x = -1 << k;
    show_int(x);

    x = ((1 << k) - 1) << j;
    show_int(x);
}

//2.90
float fpwr2(int x)
{
    //TODO
    return 0;
}

typedef unsigned float_bits;
//2.92
float_bits float_negate(float_bits f)
{
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if(exp == 0xff && frac)
        return f;

    unsigned sign = !(f >> 31);
    return (sign << 31) | (exp << 23) | frac;
}

//2.93
float_bits float_absval(float_bits f)
{
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if(exp == 0xff && frac)
        return f;

    return (0x0 << 31) | (exp << 23) | frac;
}

//2.94
float_bits float_twice(float_bits f)
{
    unsigned exp = (f >> 23 & 0xff) + 1;
    unsigned frac = f & 0x7fffff;
    if(exp == 0xff)
        return f;
    else if(exp == 0)
        frac <<= 1;
    else if(exp == 0xff - 1)
    {
        exp = 0xff;
        frac = 0;
    }
    else
        exp += 1;

    unsigned sign = f >> 31;
    return (sign << 31) | (exp << 23) | frac;
}

//2.95
float_bits float_half(float_bits f)
{
    //TODO
    return 0;
}

//2.96
int float_f2i(float_bits f)
{
    unsigned exp = (f >> 23) & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned sign = f >> 31;
    unsigned bias = 0x7f;
    int ans;
    unsigned E, M;

    if(exp >= 0 && exp < bias)
        ans = 0;
    else if(exp >= 31 + bias)
        ans = 0x80000000;
    else
    {
        E = exp - bias;
        M = frac | 0x800000;

        if(E > 23)
            ans = M << (E - 23);
        else
            ans = M >> (23 - E);
    }

    if(sign)
        return -ans;
    else
        return ans;
}

//2.97
float_bits float_i2f(int i)
{
    //TODO
    return 0;
}