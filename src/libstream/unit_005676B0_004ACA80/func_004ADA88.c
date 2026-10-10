#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AD9E0(s32);                         /* extern */
s32 func_004ADE90(void *, s32, s32);            /* extern */

extern char D_005DAE30[];
struct func_004ADA88_arg0 {
    char pad0[0x54];
    s32 unk54;
};

void func_004ADA88(void *arg0, s32 arg1, s32 arg2) {
    ((struct func_004ADA88_arg0 *)arg0)->unk54 = (s32)D_005DAE30;
    func_004AD9E0(arg0 + 0x4C);
    func_004ADE90(arg0, arg1, arg2);
}
