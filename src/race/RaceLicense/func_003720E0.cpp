#include "types.h"

struct VE {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

extern "C" void func_00355050(void *arg0);

static inline void vcall(char *o) {
    VE *e = (VE *)(*(char **)(o + 0x14) + 0x28);
    e->fn(o + e->delta);
}

extern "C" void func_003720E0(void *arg0) {
    char *self;
    char *s1;
    char *s0;

    func_00355050(arg0);
    self = (char *)arg0;
    if ((*(s32 *)(self + 0x58) & 0x410) == 0x10) {
        s1 = self + 0x560C;
        s0 = self + 0x54BC;
        s32 n = 2;
        do {
            if (*(s32 *)(self + 0x590C) != 0) {
                if (*(u8 *)s0 != 0) {
                    vcall(s0);
                }
            } else {
                if (*(u8 *)s1 != 0) {
                    vcall(s1);
                }
            }
            n--;
            s1 += 0x94;
            s0 += 0x70;
        } while (n >= 0);

        {
            char *a5 = self + 0x5854;
            if (*(s32 *)(a5 + 0x6C) > 0) {
                if (*(u8 *)a5 != 0) {
                    vcall(a5);
                }
                a5 = self + 0x58EC;
                if (*(u8 *)a5 != 0) {
                    vcall(a5);
                }
            }
        }
    }
}
