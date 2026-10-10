#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0030C648(s32, s32);                    /* extern */

struct func_004251C0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_004251C0(void *arg0, s32 arg1) {
    func_0030C648(((struct func_004251C0_arg0 *)arg0)->unk4, M2C_FIELD(((arg1 * 0x14) + arg0), s32 *, 0x30));
}
