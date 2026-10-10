#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00423F60(s32);                             /* extern */
s32 func_00424060(s32, s32, s32, s32);          /* extern */

s32 func_00424008(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00424060(arg0, arg1, arg2, func_00423F60(arg3));
    return arg0;
}
