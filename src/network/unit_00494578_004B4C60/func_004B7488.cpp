#include "types.h"

extern "C" s32 func_004B70F8(s32 arg0);

struct Out8 { s16 a; s8 b[5]; s8 pad; };

extern "C" s32 func_004B7488(s32 arg0, s32 arg1)
{
    u8 *s = (u8 *)arg1;
    Out8 t;
    s32 r1, r2, r3, r4, r5, r6;
    u8 b6, b5, b3, b2, b1;

    r1 = func_004B70F8(s[7]);
    b6 = s[6];
    t.a = (s16)(r1 + 0x7D0);
    r2 = func_004B70F8(b6);
    b5 = s[5];
    t.b[0] = (s8)r2;
    r3 = func_004B70F8(b5);
    b3 = s[3];
    t.b[1] = (s8)r3;
    r4 = func_004B70F8(b3);
    b2 = s[2];
    t.b[2] = (s8)r4;
    r5 = func_004B70F8(b2);
    b1 = s[1];
    t.b[3] = (s8)r5;
    r6 = func_004B70F8(b1);
    t.b[4] = (s8)r6;
    *(Out8 *)arg0 = t;
    return arg0;
}
