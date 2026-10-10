#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_005857DC[];
s32 func_0011C780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return M2C_FIELD(*(void **)D_005857DC, u8 *, 0x1D94) != 0;
}
