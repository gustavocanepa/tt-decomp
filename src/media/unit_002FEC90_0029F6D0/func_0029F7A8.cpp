#include "types.h"

extern "C" u8 HIO__read8(void *arg0);

extern "C" s32 func_0029F7A8(s32 arg0, u8 *arg1) {
    s32 s1 = arg0;
    *arg1 = HIO__read8((void *)s1);
    return s1;
}
