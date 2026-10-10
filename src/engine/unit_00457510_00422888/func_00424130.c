/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00423C60(void *, s32);             /* extern */

struct func_00424130_arg0 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00424130_arg1 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_00424130(struct func_00424130_arg0 *arg0, struct func_00424130_arg1 *arg1) {
    arg0->unk4 = (s32) (arg1->unk8 - arg1->unk0);
    func_00423C60(arg1, 0);
    func_00423C60(arg1, 0);
}
