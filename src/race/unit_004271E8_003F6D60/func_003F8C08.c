#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F8C00();                             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */
s32 func_005524A8(s32, s32);                    /* extern */

void func_003F8C08(s32 arg0, s32 arg1) {
    func_004F64C4(arg1, arg0, func_003F8C00());
    func_005524A8(arg1, func_003F8C00(arg0));
}
