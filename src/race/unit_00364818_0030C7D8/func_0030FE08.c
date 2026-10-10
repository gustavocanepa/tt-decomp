#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0030FA20();                            /* extern */
s32 func_0030FA90(s32, s32, s32);               /* extern */
s32 func_0030FC70(s32, s32, s32);               /* extern */

void func_0030FE08(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0030FA20();
    if (arg2 != 0) {
        func_0030FC70(arg0, arg1, arg3);
        func_0030FA90(arg0, arg1, arg3);
    }
}
