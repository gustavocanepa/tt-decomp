#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F64C4(s32, void *, s32);            /* extern */

struct func_0041DFB0_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_0041DFB0(struct func_0041DFB0_arg0 *arg0, s32 arg1) {
    func_004F64C4(arg1, arg0, arg0->unk8);
    return arg1;
}
