#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00411168();                                /* extern */
s32 func_00411298(s32, s32, s32);               /* extern */

void SPEC_DATABASE__DatabaseTable__getRow(s32 arg0, s32 arg1, s32 arg2) {
    func_00411298(arg0, func_00411168(), arg2);
}
