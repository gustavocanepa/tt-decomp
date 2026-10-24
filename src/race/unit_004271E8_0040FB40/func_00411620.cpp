#include "types.h"
struct T { char pad[0xC]; int c; };
struct O { T *t; char pad[0x18]; u8 *f1C; };
extern "C" {
void func_004F64C4(void *, const void *, unsigned);
void func_00411620(O *o, u8 *p, u8 *dst) {
    u8 b = *p++;
    int tag = b >> 6;
    int n = o->t->c;
    int idx = b & 0x3F;
    switch (tag) {
    case 0:
        {
            u8 *src = o->f1C + n * idx;
            return func_004F64C4(dst, src, n);
        }
    case 1:
        return func_004F64C4(dst, p, n);
    case 2: {
        u8 *src = o->f1C + n * idx;
        func_004F64C4(dst, src, n);
        u8 *q = p + (n / 8);
        if (n & 7) q = q + 1;
        for (int j = 0; j < n; j++) {
            if (((unsigned)p[j / 8] >> (j - (j / 8) * 8)) & 1) {
                dst[j] = *q++;
            }
        }
        break;
    }
    }
}
}
