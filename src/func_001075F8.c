#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00107570(s32 *, s32);                    /* extern */
s32 func_001075C8();                            /* extern */
s32 func_00107640();                            /* extern */
s32 func_00509108();                            /* extern */

s32 func_001075F8(s32 arg0, s32 arg1) {
    s32 sp[2];

    sp[0] = arg0;
    func_00509108();
    func_00107570(sp, arg1);
    func_00107640();
    func_001075C8();
    return 0;
}
