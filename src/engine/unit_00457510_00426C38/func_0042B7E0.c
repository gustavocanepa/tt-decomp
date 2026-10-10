#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00560898();                    /* extern */

struct func_0042B7E0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_0042B7E0(void *arg0, s32 arg1, s32 arg2) {
    func_00560898();
    func_00560898(arg0 + 4, arg1);
    func_00560898(arg0 + 8, arg1);
    func_00560898(arg0 + 0xC, arg1);
    func_00560898(arg0 + 0x10, arg1);
    if (arg2 != 0) {
        ((struct func_0042B7E0_arg0 *)arg0)->unk14 = (s32) (((struct func_0042B7E0_arg0 *)arg0)->unk14 + arg1);
    }
}
