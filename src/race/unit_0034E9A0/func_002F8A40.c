#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00439628(s32, f32, f32);           /* extern */

extern char D_005865D0[];
struct func_002F8A40_temp_v0 {
    char pad0[0x4E4];
    f32 unk4E4;
    f32 unk4E8;
};

void func_002F8A40(s32 arg0) {
    struct func_002F8A40_temp_v0 *temp_v0;

    temp_v0 = arg0 + 0x104;
    func_00439628((s32)D_005865D0, temp_v0->unk4E8, temp_v0->unk4E4);
}
