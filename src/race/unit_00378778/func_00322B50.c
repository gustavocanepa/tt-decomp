#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322B50_arg0 {
    char pad0[0x2A8];
    s32 unk2A8;
    f32 unk2AC;
    f32 unk2B0;
    f32 unk2B4;
    char pad2B8[0x8];
    s32 unk2C0;
};

void func_00322B50(struct func_00322B50_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1, f32 fparg2) {
    arg0->unk2A8 = 1;
    arg0->unk2B0 = fparg0;
    arg0->unk2B4 = fparg1;
    arg0->unk2AC = fparg2;
    arg0->unk2C0 = arg1;
}
