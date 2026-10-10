#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */

extern char D_005D8BC8[];
struct func_003F9530_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_003F9530(struct func_003F9530_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_00400D68();
    arg0->unk18 = arg6;
    arg0->unk4 = arg1;
    arg0->unk8 = arg2;
    arg0->unkC = arg3;
    arg0->unk10 = arg4;
    arg0->unk14 = arg5;
    arg0->unk0 = (s32)D_005D8BC8;
}
