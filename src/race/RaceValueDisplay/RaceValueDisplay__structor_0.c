#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceValueDisplayBase__structor_1();                            /* extern */
s32 RaceValueDisplay__setFont(void *, s32);             /* extern */

extern char D_005D0A50[];
extern char D_005F5600[];
struct RaceValueDisplay__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x70];
    s32 unk88;
    s32 unk8C;
};

void RaceValueDisplay__structor_0(struct RaceValueDisplay__structor_0_arg0 *arg0) {
    RaceValueDisplayBase__structor_1();
    arg0->unk88 = 0;
    arg0->unk8C = 0;
    arg0->unk14 = (s32)D_005D0A50;
    RaceValueDisplay__setFont(arg0, (s32)D_005F5600);
}
