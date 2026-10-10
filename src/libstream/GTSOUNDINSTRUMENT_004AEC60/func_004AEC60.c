#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_0060C3B8[];
struct func_004AEC60_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_004AEC60(struct func_004AEC60_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unkC = 0;
    arg0->unk4 = (s32)D_0060C3B8;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
}
