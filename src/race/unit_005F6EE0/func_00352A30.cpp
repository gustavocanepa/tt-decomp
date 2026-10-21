#include "types.h"

extern char D_005F41D0[];

extern "C" void RaceMessageDisplay__setFont(char *, char *, s32);
extern "C" void Oscillator__setCount(void *, s32, s32);
extern "C" void Oscillator__setCycle(void *, f32, f32);
extern "C" void RaceMessageDisplay__setMessage(char *, char *, f32, f32);

extern "C" void func_00352A30(char *arg0, char *arg1, s32 arg2) {
    char *temp_s1;

    temp_s1 = arg0 + 0x224C;
    RaceMessageDisplay__setFont(temp_s1, D_005F41D0, arg2 != 0);
    *(s32 *)(temp_s1 + 0x20) = 0x80C8C8C8;
    Oscillator__setCount(arg0 + 0x2280, -1, 1);
    Oscillator__setCycle(arg0 + 0x2280, 1.0f, 1.0f);
    RaceMessageDisplay__setMessage(temp_s1, arg1, 0x1.47AE14p-5f, 0.0f);
}
