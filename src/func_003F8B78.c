#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_003F8A40(void *, s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

extern char D_005F9C58[];
void func_003F8B78(void *arg0, s32 arg1) {
    func_003F8A40(arg0, arg1, (s32)D_005F9C58, 0xB, 1, M2C_FIELD(arg0, s32 *, 0xC04) - 1);
}
