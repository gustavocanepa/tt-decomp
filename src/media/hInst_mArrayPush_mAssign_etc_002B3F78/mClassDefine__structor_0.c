#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002AC0B0(s32, s32);                    /* extern */
s32 func_002C0EB0();                            /* extern */

extern char D_005C6DF0[];
struct mClassDefine__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x10];
    s32 unk1C;
};

void mClassDefine__structor_0(void *arg0, s32 *arg1, s32 arg2) {
    func_002C0EB0();
    ((struct mClassDefine__structor_0_arg0 *)arg0)->unk4 = (s32)D_005C6DF0;
    ((struct mClassDefine__structor_0_arg0 *)arg0)->unk8 = (s32) *arg1;
    func_002AC0B0(arg0 + 0xC, arg2);
    ((struct mClassDefine__structor_0_arg0 *)arg0)->unk1C = 0;
}
