#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0047BF80();                                /* extern */
s32 func_0047BFD8(s32, s32);                    /* extern */
s32 func_0047C018(s32, s32);                    /* extern */

void func_0056DD30(s32 arg0, s32 arg1) {
    if (func_0047BF80() != 0) {
        func_0047C018(arg0, arg1);
        return;
    }
    func_0047BFD8(arg0, arg1);
}
