#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_003FC930(s32, s32);                /* extern */
s32 func_004A45D0(void *);                      /* extern */

extern char D_005A7DC8[];
struct mOption__structor_2_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mOption__structor_2(void *arg0, s32 arg1) {
    ((struct mOption__structor_2_arg0 *)arg0)->unk4 = (s32)D_005A7DC8;
    func_003FC930(arg0 + 0x18, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_004A45D0(arg0);
    }
}
