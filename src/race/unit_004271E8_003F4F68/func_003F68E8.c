#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */
s32 func_004AF530(s32, s32, s32);       /* extern */

extern char D_005D8A78[];
struct func_003F68E8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

s32 func_003F68E8(struct func_003F68E8_arg0 *arg0) {
    s32 temp_v0;

    func_00400D68();
    arg0->unk0 = (s32)D_005D8A78;
    temp_v0 = func_004AF530(0x7D5, 4, 2);
    arg0->unk8 = 0;
    arg0->unk4 = temp_v0;
}
