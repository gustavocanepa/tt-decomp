#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003F4400(void *, s32);                 /* extern */
s32 func_004A8268(s32, s32);                        /* extern */

struct func_003F2108_arg0 {
    s32 unk0;
    char pad4[0x408];
    s32 unk40C;
    s32 unk410;
    s32 unk414;
};

void func_003F2108(struct func_003F2108_arg0 *arg0, s32 arg1) {
    if (arg0->unk410 != 0) {
        if (func_004A8268(arg1, arg0->unk414) == 0) {
            arg0->unk40C = 1;
            func_003F4400(arg0, arg0->unk410);
            arg0->unk0 = 1;
        }
    } else {
        arg0->unk0 = 1;
    }
}
