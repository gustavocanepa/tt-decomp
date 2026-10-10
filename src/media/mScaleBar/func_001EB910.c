#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001EBB88(void *, s32);                 /* extern */
s32 func_001EC1A8(void *, f32);                 /* extern */
s32 func_001EC1D8(void *, f32);                 /* extern */
s32 func_0020CF10();                            /* extern */

struct func_001EB910_arg0 {
    char pad0[0xDC];
    f32 unkDC;
};

s32 func_001EB910(struct func_001EB910_arg0 *arg0, s32 arg1) {
    func_0020CF10();
    func_001EC1A8(arg0, arg0->unkDC);
    func_001EC1D8(arg0, arg0->unkDC);
    func_001EBB88(arg0, arg1);
    return 1;
}
