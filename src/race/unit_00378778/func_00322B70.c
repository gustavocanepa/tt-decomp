#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322B70_arg0 {
    char pad0[0x2A8];
    s32 unk2A8;
    char pad2AC[0xC];
    f32 unk2B8;
    char pad2BC[0x4];
    s32 unk2C0;
};

void func_00322B70(struct func_00322B70_arg0 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk2A8 = 2;
    arg0->unk2B8 = fparg0;
    arg0->unk2C0 = arg1;
}
