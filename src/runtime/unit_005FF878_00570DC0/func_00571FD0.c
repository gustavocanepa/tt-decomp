/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00571FD0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

void func_00571FD0(struct func_00571FD0_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk18 = arg1;
    arg0->unk1C = (s32) (arg1 + arg2);
    arg0->unk14 = arg1;
}
