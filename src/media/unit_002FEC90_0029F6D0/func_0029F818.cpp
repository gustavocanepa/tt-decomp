#include "types.h"

extern "C" s32 func_0029F6F8(void *arg0);

extern "C" s32 func_0029F818(void *arg0, s16 *arg1) {
    *arg1 = (s16)func_0029F6F8(arg0);
    return (s32)arg0;
}
