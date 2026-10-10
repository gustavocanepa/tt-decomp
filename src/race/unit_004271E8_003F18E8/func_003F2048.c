#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F4010();                            /* extern */

extern char D_005D7BF0[];
struct func_003F2048_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x404];
    s32 unk40C;
    s32 unk410;
    s32 unk414;
};

void func_003F2048(struct func_003F2048_arg0 *arg0, s32 arg1, s32 arg2) {
    func_003F4010();
    arg0->unk414 = arg1;
    arg0->unk410 = arg2;
    arg0->unk4 = (s32)D_005D7BF0;
    arg0->unk40C = 0;
}
