#include "types.h"

extern "C" void *D_00579774;
extern "C" char D_005DFCC0[];

extern "C" void *func_00117128(void *arg0, s32 arg1) {
    void *v = D_00579774;
    if (v == 0) {
        return D_005DFCC0;
    }
    return (char *)v + (arg1 << 7) + 4;
}
