#include "types.h"

extern char D_005F5A08[];

extern "C" void RaceMessageDisplay__setFont(void *arg0, s32 arg1, s32 arg2);
extern "C" void RaceMessageDisplay__clear(void *self);
extern "C" void RaceMessageDisplay__show(void *arg0, f32 fparg0, f32 fparg1);
extern "C" void RaceEventDisplay__clear(void *arg0, f32 fparg0);
extern "C" void func_0035A5F0(void *arg0, s32 arg1, s32 arg2);
extern "C" void AutomaticFader__reset(void *arg0);
extern "C" void RaceDisplayObjectBase__setAlignment(void *arg0, s8 arg1, s8 arg2);

extern "C" void func_003630E0(char *arg0) {
    f32 z = 0.0f;
    char *s1 = arg0 + 0x3C;
    s32 str = (s32)D_005F5A08;

    *(f32 *)(arg0 + 0x18) = z;
    *(f32 *)(arg0 + 0x1C) = z;
    AutomaticFader__reset(arg0 + 0x20);
    arg0 += 0x18C;
    RaceMessageDisplay__clear(s1);
    RaceMessageDisplay__show(s1, z, z);
    *(s32 *)s1 = (*(s32 *)s1 & -0x100) | 1;
    RaceMessageDisplay__setFont(s1, str, 0);
    RaceDisplayObjectBase__setAlignment(s1, 2, 1);
    RaceEventDisplay__clear(arg0, z);
    func_0035A5F0(arg0, str, 0);
    RaceDisplayObjectBase__setAlignment(arg0, 2, 1);
}
