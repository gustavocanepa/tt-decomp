#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002AC0B0(s32, s32);                    /* extern */
s32 func_002C0EB0();                            /* extern */

extern char D_005C6760[];
struct mModuleDefine__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x10];
    s32 unk18;
};

void mModuleDefine__structor_0(void *arg0, s32 arg1) {
    func_002C0EB0();
    ((struct mModuleDefine__structor_0_arg0 *)arg0)->unk4 = (s32)D_005C6760;
    func_002AC0B0(arg0 + 8, arg1);
    ((struct mModuleDefine__structor_0_arg0 *)arg0)->unk18 = 0;
}
