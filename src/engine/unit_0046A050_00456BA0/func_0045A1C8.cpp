#include "types.h"

struct Writer {
    char pad0[4];
    s32 end;      /* 0x04 */
    s32 pos;      /* 0x08 */
    s32 bits;     /* 0x0C */
    u8 *ptr;      /* 0x10 */
    s32 err;      /* 0x14 */
    s32 err2;     /* 0x18 */
};

extern "C" void func_0045A1C8(Writer *arg0, s32 arg1, s32 arg2) {
    u32 v = (u32)arg2;

    if (arg0->end - arg0->pos < 8) {
        arg0->err = 1;
        arg0->err2 = 1;
        return;
    }

    arg0->bits = arg0->bits - arg1;
    u32 t = (v & ((1u << arg1) - 1)) << (arg0->bits + 8);
    u8 *p = arg0->ptr;
    p[0] = (u8)(p[0] | (t >> 8));

    if (arg0->bits <= 0) {
        u8 *q = arg0->ptr;
        if (q[0] == 0xFF) {
            arg0->ptr = q + 1;
            arg0->pos++;
            q[1] = 0;
            q = arg0->ptr;
        }
        arg0->ptr = q + 1;
        arg0->pos++;
        q[1] = (u8)t;
        arg0->bits = arg0->bits + 8;
    }
}
