#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_003CCD90(s32, s32);                  /* extern */
void *func_0041FFD8(s32, s32);                  /* extern */

struct func_00375428_temp_v0 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00375428_temp_v0_2 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
};

struct func_00375428_arg0 {
    char pad0[0xDD4];
    f32 unkDD4;
    f32 unkDD8;
};

void func_00375428(void *arg0) {
    s32 temp_a0;
    struct func_00375428_temp_v0 *temp_v0;
    struct func_00375428_temp_v0_2 *temp_v0_2;

    ((struct func_00375428_arg0 *)arg0)->unkDD4 = 0x0.0p+0f;
    ((struct func_00375428_arg0 *)arg0)->unkDD8 = 0x0.0p+0f;
    temp_v0 = func_003CCD90(arg0 + 0xDF0, 8);
    if (temp_v0 != NULL) {
        temp_a0 = temp_v0->unk4;
        if (temp_a0 != 0) {
            temp_v0_2 = func_0041FFD8(temp_a0, 0x800001);
            if (temp_v0_2 != NULL) {
                ((struct func_00375428_arg0 *)arg0)->unkDD4 = (f32) temp_v0_2->unk4;
                ((struct func_00375428_arg0 *)arg0)->unkDD8 = (f32) temp_v0_2->unk8;
            }
        }
    }
    if ((((struct func_00375428_arg0 *)arg0)->unkDD4 == 0x0.0p+0f) && (((struct func_00375428_arg0 *)arg0)->unkDD8 == 0x0.0p+0f)) {
        ((struct func_00375428_arg0 *)arg0)->unkDD4 = 0x1.0000000000000p-1f;
        ((struct func_00375428_arg0 *)arg0)->unkDD8 = 0x1.0000000000000p-2f;
    }
}
