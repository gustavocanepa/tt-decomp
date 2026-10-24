#include "types.h"
extern char D_00769530[];
extern char D_00769538[];
extern char D_00769540[];
extern char D_005F97E0[];
extern char D_005F9828[];
extern char D_005F98A0[];
extern "C" void func_004AC368(void *, void *, s32);

extern "C" void func_003F6DF0(s32 init, s32 prio)
{
    if (prio == 0xFFFF && init == 1) func_004AC368(D_00769530, D_005F97E0, 5);
    if (prio == 0xFFFF && init == 1) func_004AC368(D_00769538, D_005F9828, 5);
    if (prio == 0xFFFF && init == 1) func_004AC368(D_00769540, D_005F98A0, 8);
}
