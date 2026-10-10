#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F9A0_arg0 {
    char pad0[0x48];
    f32 unk48;
    char pad4C[0x54];
    s32 unkA0;
    s32 unkA4;
    char padA8[0x4];
    s32 unkAC;
    f32 unkB0;
};

void func_0045F9A0(struct func_0045F9A0_arg0 *arg0) {
    arg0->unkAC = (s32) arg0->unkA0;
    arg0->unkA4 = (s32) (arg0->unkA4 + 1);
    arg0->unkB0 = (f32) arg0->unk48;
}
