#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00447D00(s32, s32);                    /* extern */

struct func_00441D38_arg1 {
    char pad0[0x70];
    s32 unk70;
};

s32 *func_00441D38(s32 *arg0, struct func_00441D38_arg1 *arg1, s32 arg2, s32 arg3) {
    func_00447D00(arg3, arg2);
    arg1->unk70 = 1;
    *arg0 = 1;
    return arg0;
}
