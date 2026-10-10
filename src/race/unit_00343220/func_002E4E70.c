#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_002FD378(s32);                           /* extern */

struct func_002E4E70_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

struct func_002E4E70_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_002E4E70(void *arg0, f32 fparg0) {
    f32 *var_a0;
    s32 var_a1;
    struct func_002E4E70_temp_v0 *temp_v0;

    temp_v0 = func_002FD378(((struct func_002E4E70_arg0 *)arg0)->unk10);
    var_a1 = 0;
    if (temp_v0->unk1 != 0) {
        var_a0 = arg0 + 0x1C8;
        do {
            *var_a0 = fparg0;
            var_a1 += 1;
            var_a0 += 0x3D;
        } while (var_a1 < (s32) temp_v0->unk1);
    }
}
