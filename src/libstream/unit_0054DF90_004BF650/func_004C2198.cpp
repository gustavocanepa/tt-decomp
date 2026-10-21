#include "types.h"

extern "C" void func_004C2098(void *self);
extern "C" void *exception__structor_0(s32 n);

extern s32 D_00598C7C;

extern "C" s32 func_004C2198(void) {
    s32 cur = D_00598C7C;
    if (cur == 0) {
        s32 t = (s32)exception__structor_0(0x44);
        func_004C2098((void *)t);
        D_00598C7C = t;
        return t;
    }
    return cur;
}
