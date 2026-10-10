/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D8830(void *, s32);                 /* extern */
s32 func_002D8C18(void *, s32);             /* extern */
s32 func_003EB020(s32);                             /* extern */

struct func_002D87A0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

void func_002D87A0(struct func_002D87A0_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    if ((arg0->unk1C != 0) && (arg0->unk20 == 0)) {
        temp_v0 = func_003EB020(arg1);
        if (temp_v0 & 1) {
            func_002D8C18(arg0, 1);
        }
        if (temp_v0 & 0x8000) {
            func_002D8C18(arg0, 0);
        }
        func_002D8830(arg0, arg1);
    }
}
