#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B50F0(s32, s16, s16);               /* extern */

struct func_00481A90_arg0 {
    char pad0[0x4];
    s16 unk4;
    s16 unk6;
};

void func_00481A90(struct func_00481A90_arg0 *arg0, s32 arg1) {
    func_004B50F0(arg1, arg0->unk4, arg0->unk6);
}
