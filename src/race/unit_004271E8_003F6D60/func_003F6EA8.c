#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */
s32 func_004F6678(s32, s32, s32);       /* extern */

extern char D_005D8AC8[];
void func_003F6EA8(s32 *arg0) {
    func_00400D68();
    *arg0 = (s32)D_005D8AC8;
    func_004F6678(arg0 + 2, 0, 0x88);
}
