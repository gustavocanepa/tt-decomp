#include "types.h"
struct S { char pad[0x5C]; u32 v; };
extern "C" void func_00460A48(void);
extern u32 D_00586EFC;
static inline u32 hex(u32 c, u32 k) {
    if (c - 0x30 < 10) return c - 0x30;
    if (c - 0x61 < 6) return c - 0x57;
    if (c - 0x41 < 6) return c - 0x37;
    return k;
}
extern "C" int func_00462020(u8 **p, int flag, S *s) {
    u32 acc;
    int i;
    acc = 0;
    u32 k = 15;
    i = 2;
    do {
        u8 *q = *p;
        u8 c = *q;
        *p = q + 1;
        u32 d = hex(c, k);
        i--;
        acc >>= 8;
        acc |= ((d * 0x11) & 0xFF) << 16;
    } while (i >= 0);
    if (flag == 0) {
        acc |= s->v & 0xFF000000;
        D_00586EFC = acc;
        func_00460A48();
    }
    return 0;
}
