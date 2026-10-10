#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00184888(s32);
void func_002A7578(s32, s32 *);
s32 func_004A45F8(s32);
void func_00184938(s32 arg0) {
    s32 sp[4];
    s32 temp_v0;
    temp_v0 = func_004A45F8(0xC8);
    func_00184888(temp_v0);
    sp[0] = temp_v0;
    func_002A7578(arg0, sp);
}
