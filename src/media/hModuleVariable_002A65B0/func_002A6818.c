#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7590(s32, s32);                    /* extern */
s32 func_002BC0C8(void *, s32);                 /* extern */
s32 hVariable__structor_0();                            /* extern */

extern char D_005C54E8[];
struct func_002A6818_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002A6818(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    hVariable__structor_0();
    ((struct func_002A6818_arg0 *)arg0)->unk4 = (s32)D_005C54E8;
    func_002A7590(arg0 + 0x14, arg2);
    func_002BC0C8(arg0 + 0x18, arg3);
}
