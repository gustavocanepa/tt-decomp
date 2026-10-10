#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00394B10_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x2C];
    s32 unk38;
    f32 unk3C;
    s32 unk40;
};

void func_00394B10(struct func_00394B10_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk3C = 0x1.0000000000000p+0f;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk38 = 0;
    arg0->unk40 = 0;
}
