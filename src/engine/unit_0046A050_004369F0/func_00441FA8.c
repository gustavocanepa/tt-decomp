#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00447398(void *, s32);                 /* extern */
s32 func_00447D00(s32, s32);                    /* extern */

struct func_00441FA8_arg1 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    s32 unk70;
};

s32 *func_00441FA8(s32 *arg0, struct func_00441FA8_arg1 *arg1, s32 arg2, s32 arg3) {
    func_00447D00(arg3, arg2);
    func_00447398(arg1, arg1->unk64 - 1);
    arg1->unk70 = 1;
    *arg0 = 1;
    return arg0;
}
