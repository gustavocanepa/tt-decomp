#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void mCarGarage__structor_0(s32);
void func_002A7578(s32, s32 *);
s32 func_004A45F8(s32);
void func_00132788(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_004A45F8(0x198);
    mCarGarage__structor_0(temp_v0);
    sp[0] = temp_v0;
    func_002A7578(arg0, sp);
}
