#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005BB4C8[];
struct func_0024DF50_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_0024DF50(struct func_0024DF50_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_005BB4C8;
    arg0->unk10 = 0x1.0000000000000p+0f;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
}
