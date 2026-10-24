#include "types.h"

extern "C" s32 func_004A45F8(s32 arg0);
extern "C" void mCarGarage__structor_1(s32 arg0, s32 arg1);
extern "C" void func_002A7578(s32 arg0, s32 *arg1);

extern "C" void func_001327D8(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    s32 s1 = arg1;
    s32 s2 = func_004A45F8(0x198);
    mCarGarage__structor_1(s2, s1);
    s32 local = s2;
    func_002A7578(s0, &local);
}
