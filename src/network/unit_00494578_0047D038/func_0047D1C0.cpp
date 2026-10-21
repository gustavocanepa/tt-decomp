#include "types.h"

struct VEntry4AD {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

extern "C" void func_004AEAF8(void *arg0);

extern "C" void func_0047D1C0(void *arg0) {
    char *self = (char *)arg0;
    char *p64;
    s32 *p4c;
    s32 *p1;
    VEntry4AD *e;

    if (*(s32 *)(self + 0xA0) != 0)
        return;
    p64 = self + 0x64;
    p4c = (s32 *)(self + 0x4C);
    for (;;) {
        func_004AEAF8(p64);
        if (*p4c != 0) {
            do {
                if (*(s32 *)(self + 0xA0) != 0)
                    return;
                e = (VEntry4AD *)(*(char **)(self + 0xA4) + 0x58);
                e->fn(self + e->delta);
            } while (*p4c != 0);
        }
        p1 = (s32 *)(self + 0x58);
        if (*p1 != 0) {
            do {
                if (*(s32 *)(self + 0xA0) != 0)
                    return;
                e = (VEntry4AD *)(*(char **)(self + 0xA4) + 0x70);
                e->fn(self + e->delta);
            } while (*p1 != 0);
        }
        if (*(s32 *)(self + 0xA0) != 0)
            return;
    }
}
