#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D8598();                            /* extern */
s32 func_002D8E80(void *);                      /* extern */
s32 func_002D8F18(void *);                      /* extern */
s32 func_003EB020(s32);                             /* extern */

struct func_002D8518_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

s32 func_002D8518(struct func_002D8518_arg0 *arg0, s32 arg1) {
    if ((arg0->unk1C == 0) || (arg0->unk20 != 0)) {
        func_002D8598();
    }
    if (func_003EB020(arg1) & 0x20) {
        func_002D8E80(arg0);
    }
    if (func_003EB020(arg1) & 0x40) {
        func_002D8F18(arg0);
    }
}
