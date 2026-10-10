#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F97A8();                             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */
s32 func_0055CCF8(s32, s32);                    /* extern */

void func_003F9800(s32 arg0, s32 arg1) {
    func_004F64C4(arg0, arg1, func_003F97A8());
    func_0055CCF8(arg1, func_003F97A8(arg0));
}
