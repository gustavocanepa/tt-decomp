#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7590(s32, s32);                    /* extern */
s32 hVariable__structor_0();                            /* extern */

extern char D_005C4BB0[];
struct hLocalVariable__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void hLocalVariable__structor_0(void *arg0, s32 arg1, s32 arg2) {
    hVariable__structor_0();
    ((struct hLocalVariable__structor_0_arg0 *)arg0)->unk4 = (s32)D_005C4BB0;
    func_002A7590(arg0 + 0x14, arg2);
}
