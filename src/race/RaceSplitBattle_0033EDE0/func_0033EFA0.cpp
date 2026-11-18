#include "types.h"

struct VE32F6 {
    s16 delta;
    s16 index;
    void *fn;
};

extern "C" void func_0031AA88(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0033EFA0(void *arg0) {
    char *self = (char *)arg0;

    VE32F6 *e1 = (VE32F6 *)(*(char **)(self + 0x64) + 0xD0);
    char *s2 = (char *)((void *(*)(void *, s32))e1->fn)(self + e1->delta, 0);

    VE32F6 *e2 = (VE32F6 *)(*(char **)s2 + 0xB8);
    ((void (*)(void *, s32, s32, s32))e2->fn)(s2 + e2->delta,
                                              *(s32 *)(self + 0x6C),
                                              *(s32 *)(self + 0x70),
                                              1);

    for (s32 i = 0; i < 2; i++) {
        VE32F6 *e3 = (VE32F6 *)(*(char **)(self + 0x64) + 0x228);
        s32 r = ((s32 (*)(void *, s32))e3->fn)(self + e3->delta, i);
        func_0031AA88((s32)s2, i, r);
    }

    VE32F6 *e4 = (VE32F6 *)(*(char **)(self + 0x64) + 0x188);
    ((void (*)(void *))e4->fn)(self + e4->delta);
}
