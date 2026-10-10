#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004AC4D0(void *, s32, s32);
struct func_002830D0_arg0 {
    char pad0[0xE8];
    s32 unkE8;
    char padEC[0x10];
    s32 unkFC;
    s32 unk100;
    char pad104[0xC];
    f32 unk110;
};

void func_002830D0(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_002830D0_arg0 *)arg0)->unkFC = arg1;
    ((struct func_002830D0_arg0 *)arg0)->unk100 = arg2;
    func_004AC4D0((s8 *)arg0 + 0xE8, arg1, arg2 + 1);
    ((struct func_002830D0_arg0 *)arg0)->unk110 = (f32) ((struct func_002830D0_arg0 *)arg0)->unkE8;
}
