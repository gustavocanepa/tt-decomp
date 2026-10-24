#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_00488D20(void *, s32, s32, s32, s32);  /* extern */

void func_00571088(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00488D20(arg0, M2C_FIELD(arg0, s32 *, 0x7C), arg1, arg2, arg3);
}
