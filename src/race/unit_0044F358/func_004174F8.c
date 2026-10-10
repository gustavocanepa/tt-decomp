#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00553E10(s32, s32);                    /* extern */
s32 func_005666E8(s32, s32);                    /* extern */

s32 func_004174F8(s32 arg0, s32 arg1) {
    func_005666E8(arg0 + 4, arg1 + 4);
    func_00553E10(arg0 + 0x324, arg1 + 0x324);
    return arg0;
}
