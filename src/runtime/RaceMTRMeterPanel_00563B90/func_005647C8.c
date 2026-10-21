#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005647C8_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_005647C8(struct func_005647C8_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = (s32) (arg0->unk4 + arg1);
    arg0->unk8 -= arg1;
    if (temp_v0 == 0) {
        temp_v0 = 0;
    } else {
        temp_v0 -= 1;
    }
    arg0->unk4 = temp_v0;
    return temp_v0;
}
