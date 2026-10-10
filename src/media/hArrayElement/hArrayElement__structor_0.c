#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7590(s32, s32);                    /* extern */
s32 func_002A7618();                            /* extern */

extern char D_005C3AA0[];
struct hArrayElement__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
};

void hArrayElement__structor_0(void *arg0, s32 arg1, s32 arg2) {
    func_002A7618();
    ((struct hArrayElement__structor_0_arg0 *)arg0)->unk4 = (s32)D_005C3AA0;
    func_002A7590(arg0 + 0x10, arg1);
    ((struct hArrayElement__structor_0_arg0 *)arg0)->unk14 = arg2;
}
