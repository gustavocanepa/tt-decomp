#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042D820(s32);                             /* extern */
s32 func_004C4468(s32, s32);                    /* extern */
s32 func_004C4538(s32, s32);                    /* extern */
s32 func_004C45D0();                                /* extern */

struct func_0042DB78_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    char pad14[0xC];
    s32 unk20;
};

s32 func_0042DB78(struct func_0042DB78_arg0 *arg0) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0->unk20 == 0) {
        temp_s0 = func_0042D820(arg0->unk4);
        temp_v0 = func_004C45D0();
        arg0->unk20 = temp_v0;
        func_004C4468(temp_v0, temp_s0);
        func_004C4538(arg0->unk20, arg0->unk10);
    }
}
