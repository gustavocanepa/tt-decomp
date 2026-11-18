#include "types.h"

extern "C" s32 func_001323A8(void *);
extern "C" s32 func_001323D0(void *);

extern "C" s32 func_00132418(void *self) {
    s32 r;
    if (func_001323A8(self)) r = 1;
    else r = func_001323D0(self) ? 2 : 0;
    return r;
}
