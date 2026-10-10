#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_005857DC[];
s32 func_0011C7B0(s32 arg0, s32 arg1) {
    return M2C_FIELD((*(s32 *)D_005857DC + arg1), u8 *, 0x1D90) != 0;
}
