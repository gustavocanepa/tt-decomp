#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00559778(f32, s32, s32);               /* extern */
s32 func_005616F0(s32, f32);                    /* extern */
s32 func_00561648(s32, s32, s32);                   /* extern */

struct func_003F52B8_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_003F52B8(void *arg0, f32 fparg0) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = arg0 + 8;
    temp_v0 = func_00561648(temp_s1, ((struct func_003F52B8_arg0 *)arg0)->unk0, ((struct func_003F52B8_arg0 *)arg0)->unk4);
    ((struct func_003F52B8_arg0 *)arg0)->unk4 = temp_v0;
    if (temp_v0 != 0) {
        func_005616F0(temp_v0, fparg0);
        return;
    }
    ((struct func_003F52B8_arg0 *)arg0)->unk4 = temp_s1;
    func_00559778(fparg0, temp_s1, ((struct func_003F52B8_arg0 *)arg0)->unk0);
}
