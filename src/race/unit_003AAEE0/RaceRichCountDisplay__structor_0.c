#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D0B00[];
s32 RaceValueDisplayBase__structor_1(void *);
void RaceDisplayObjectBase__setAlignment(void *, s32, s32);
struct RaceRichCountDisplay__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x50];
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s8 unk78;
};

void RaceRichCountDisplay__structor_0(struct RaceRichCountDisplay__structor_0_arg0 *arg0) {
    RaceValueDisplayBase__structor_1(arg0);
    arg0->unk68 = -1;
    arg0->unk14 = (s32)D_005D0B00;
    arg0->unk70 = 0x98967F;
    arg0->unk6C = 0;
    arg0->unk74 = 0;
    arg0->unk78 = 0;
    RaceDisplayObjectBase__setAlignment(arg0, 1, 0);
}
