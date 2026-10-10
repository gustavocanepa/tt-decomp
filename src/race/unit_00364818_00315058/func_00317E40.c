#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_004A5A68(f32);                             /* extern */

struct func_00317E40_arg0 {
    s32 unk0;
    char pad4[0x10];
    f32 unk14;
};

f32 func_00317E40(struct func_00317E40_arg0 *arg0) {
    return func_004A5A68(arg0->unk14 / ((0x1.0000000000000p+1f * (f32) arg0->unk0) / 0x1.4000000000000p+3f)) * 0x1.ca5dc20000000p+6f;
}
