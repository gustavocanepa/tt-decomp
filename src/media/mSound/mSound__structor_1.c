#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001EEAF8();                            /* extern */
s32 func_00265580(void *, s32);             /* extern */
s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005B21C8[];
struct mSound__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mSound__structor_1(void *arg0, s32 arg1) {
    ((struct mSound__structor_1_arg0 *)arg0)->unk4 = (s32)D_005B21C8;
    func_001EEAF8();
    func_00265580(arg0 + 0x14, 2);
    func_00265580(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x18, 4);
    }
}
