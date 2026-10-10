#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00346E18(s32);                         /* extern */
s32 func_0042BA18(s32);                         /* extern */

struct func_0036E340_arg0 {
    char pad0[0x39DF8];
    s32 unk39DF8;
    char pad39DFC[0x4];
    s32 unk39E00;
    s32 unk39E04;
};

void RaceFreeRun__setDescriptionVoicePause(struct func_0036E340_arg0 *arg0, s32 arg1) {
    if ((arg0->unk39E00 != 0) && (arg0->unk39DF8 != 0) && (arg0->unk39E04 != arg1)) {
        func_00346E18(arg1 ^ 1);
        func_0042BA18(arg1);
        arg0->unk39E04 = arg1;
    }
}
