#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004967F8();                                /* extern */

extern char D_00496350[];
s32 func_004962D8(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x27;
    case 18:
    case 41:
        *arg0 = (s32)D_00496350;
        return 0x33;
    default:
        return func_004967F8();
    }
}
