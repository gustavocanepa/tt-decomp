#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322BA0_arg0 {
    char pad0[0x144];
    s32 unk144;
    char pad148[0x160];
    s32 unk2A8;
    char pad2AC[0xC];
    f32 unk2B8;
    f32 unk2BC;
};

void func_00322BA0(struct func_00322BA0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk2B8 = fparg0;
    arg0->unk2A8 = 4;
    arg0->unk2BC = fparg1;
    arg0->unk144 = 0;
}
