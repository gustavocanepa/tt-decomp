#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002E6BF8();                                /* extern */
s32 func_0042FE00(void *, s32, s32);    /* extern */
s32 func_00430E70(void *, s32);             /* extern */

struct func_002E6E60_arg0 {
    char pad0[0x4];
    void *unk4;
};

s32 func_002E6E60(void *arg0) {
    if ((M2C_FIELD(((struct func_002E6E60_arg0 *)arg0)->unk4, u8 *, 0x20A29) == 0) && (func_002E6BF8() != 0)) {
        func_0042FE00(arg0 + 0x14, 6, 1);
    }
    func_00430E70(arg0, 5);
    return 1;
}
