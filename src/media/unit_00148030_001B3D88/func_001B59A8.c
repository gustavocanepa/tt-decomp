#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005AE750[];
struct func_001B59A8_arg0 {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

void func_001B59A8(struct func_001B59A8_arg0 *arg0) {
    arg0->unk0 = (s32)D_005AE750;
    arg0->unk8 = 0x1.9000000000000p+5f;
    arg0->unkC = 0x1.9999980000000p-4f;
    arg0->unk10 = 0x1.0000000000000p+5f;
    arg0->unk1C = 0x1.0000000000000p+2f;
    arg0->unk4 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
}
