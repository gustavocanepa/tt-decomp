#include "types.h"

extern char D_0059D4A8[];

extern "C" void SePlayer__Stop(void *arg0, s32 arg1);
extern "C" void func_004C7770(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void RaceCourseSound__playStop(char *arg0, s32 arg1) {
    s32 n;
    char *p;

    if (*(s32 *)arg0 != 0) {
        *(s32 *)arg0 = 0;
        p = arg0 + 4;
        n = 4;
        do {
            SePlayer__Stop(p, arg1);
            p += 0x24;
            n--;
        } while (n >= 0);
        SePlayer__Stop(arg0 + 0xB8, arg1);
        SePlayer__Stop(arg0 + 0xDC, arg1);
        SePlayer__Stop(arg0 + 0x100, arg1);
        SePlayer__Stop(arg0 + 0x124, arg1);
        *(float *)(arg0 + 0x16C) = 0.125f;
        func_004C7770(D_0059D4A8, 2, 0xFFF, 0xFFF);
        SePlayer__Stop(arg0 + 0x148, arg1);
    }
}
