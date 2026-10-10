#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F2C8_arg0 {
    char pad0[0x48];
    f32 unk48;
    f32 unk4C;
    char pad50[0x14];
    s32 unk64;
};

void func_0045F2C8(struct func_0045F2C8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk64 = 0;
    arg0->unk48 = (f32) arg1;
    arg0->unk4C = (f32) arg2;
}
