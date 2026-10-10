#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00128418(void *, s32);
void func_00128470(void *);
s32 func_001324D8(s32);
void func_002E4A90(s32);
void func_00138AD8(void) {
    s32 sp[4];
    s32 temp_s0;
    func_00128470(sp);
    temp_s0 = func_001324D8(sp[0]) + 0x4E8;
    func_00128418(sp, 2);
    func_002E4A90(temp_s0);
}
