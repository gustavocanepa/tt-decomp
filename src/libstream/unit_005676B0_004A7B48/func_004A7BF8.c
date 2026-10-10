#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FADE8(s32, s32, s32);               /* extern */

struct func_004A7BF8_arg0 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x4];
    s32 unk28;
    s32 unk2C;
};

s32 func_004A7BF8(struct func_004A7BF8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk28;
    if (temp_v0 != 0) {
        func_004FADE8(arg0->unk2C, arg0->unk20, temp_v0);
        arg0->unk28 = 0;
    }
    return 0;
}
