#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002CEDD8();                            /* extern */
s32 func_00346E18(s32);                     /* extern */
f32 func_00376C88(s32);                             /* extern */
s32 func_0042B9C0(f32);                         /* extern */
s32 func_0042B9C8();                                /* extern */

struct RaceFreeRun__virtual_06_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    char pad70[0x39D88];
    s32 unk39DF8;
    char pad39DFC[0x8];
    s32 unk39E04;
};

s32 RaceFreeRun__update(struct RaceFreeRun__virtual_06_arg0 *arg0) {
    f32 temp_f0;

    func_002CEDD8();
    if (func_0042B9C8() != 0) {
        if ((arg0->unk39DF8 != 0) && (arg0->unk39E04 == 0)) {
            func_00346E18(1);
        } else {
            func_00346E18(0);
        }
        temp_f0 = func_00376C88(arg0->unk6C);
        if (temp_f0 < 1.0f) {
            func_0042B9C0(temp_f0);
        }
    }
}
