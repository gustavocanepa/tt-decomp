#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0046B998(s32);                     /* extern */
s32 func_0046BB30(s32);                     /* extern */

void func_00469458(s32 arg0) {
    if (arg0 & 0xFF) {
        func_0046BB30(0x1001);
        return;
    }
    func_0046B998(0x1001);
}
