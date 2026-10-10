#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E3BD0(s32, s32, s32, s32);  /* extern */

struct RacePause__virtual_04_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    s32 unk18;
};

s32 RacePause__render(struct RacePause__virtual_04_arg0 *arg0) {
    s32 temp_v0;

    if (arg0->unkC != 0) {
        temp_v0 = arg0->unk18;
        if (temp_v0 != 0) {
            func_002E3BD0(temp_v0, arg0->unk14, 0x80FFFFFF, 0);
        }
    }
}
