#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C1878(s32, s32);                    /* extern */

extern char D_00598C0C[];
s32 func_004C1818(s32 arg0) {
    func_004C1878(*(s32 *)(s32)D_00598C0C, arg0);
    return *(s32 *)(s32)D_00598C0C;
}
