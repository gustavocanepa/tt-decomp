#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B33F8(s32);                         /* extern */

void func_004B2A98(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = (*arg0 * 0x11) + 0x11;
    *arg0 = temp_v0;
    func_004B33F8(temp_v0);
}
