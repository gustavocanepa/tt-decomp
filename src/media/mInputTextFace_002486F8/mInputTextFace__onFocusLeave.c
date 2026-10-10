#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_001E56B0(s32);                         /* extern */
s32 func_0020D250();                            /* extern */
s32 func_0022F7C8(s32);                             /* extern */

s32 mInputTextFace__onFocusLeave(s32 arg0, s32 arg1, s32 arg2) {
    func_0020D250();
    if (func_0022F7C8(arg2) == arg0) {
        func_001E56B0(arg1);
    }
    return 0;
}
