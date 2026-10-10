#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F9510_arg0 {
    char pad0[0x2];
    s8 unk2;
    char pad3[0x1];
    s16 unk4;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
};

void func_002F9510(struct func_002F9510_arg0 *arg0) {
    arg0->unk2 = 0;
    arg0->unk4 = 0;
    arg0->unk6 = 0;
    arg0->unk7 = 0;
    arg0->unk8 = 0;
    arg0->unkA = 0;
    arg0->unkC = 0;
    arg0->unkE = 0;
}
