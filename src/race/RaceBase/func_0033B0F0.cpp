#include "types.h"

struct VE88B50 {
    s16 delta;
    s16 index;
    void *fn;
};

extern "C" void func_0031AA88(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_0033B0F0(void *arg0) {
    char *self = (char *)arg0;
    VE88B50 *e1 = (VE88B50 *)(*(char **)(self + 0x64) + 0xD0);
    char *s1 = (char *)((void *(*)(void *, s32))e1->fn)(self + e1->delta, 0);

    VE88B50 *e2 = (VE88B50 *)(*(char **)s1 + 0xB8);
    ((void (*)(void *, s32, s32, s32))e2->fn)(s1 + e2->delta,
                                              *(s32 *)(self + 0x6C),
                                              *(s32 *)(self + 0x70),
                                              1);

    VE88B50 *e3 = (VE88B50 *)(*(char **)(self + 0x64) + 0x228);
    s32 r = ((s32 (*)(void *, s32))e3->fn)(self + e3->delta, 0);
    func_0031AA88((s32)s1, 0, r);

    VE88B50 *e4 = (VE88B50 *)(*(char **)(self + 0x64) + 0x188);
    ((void (*)(void *))e4->fn)(self + e4->delta);
}
