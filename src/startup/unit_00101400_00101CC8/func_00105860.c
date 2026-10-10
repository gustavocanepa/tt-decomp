/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0046E670(s32, s32);                    /* extern */

struct func_00105860_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
    char pad14[0x28];
    s32 unk3C;
    s32 unk40;
};

void func_00105860(struct func_00105860_arg0 *arg0, s32 arg1, s32 arg2) {
    if ((arg1 != 0) || (arg2 != 0)) {
        arg0->unk3C = arg1;
        arg0->unk40 = arg2;
        arg0->unkC = arg1;
        arg0->unk10 = arg2;
    }
    func_0046E670(arg0->unkC, arg0->unk10);
}
