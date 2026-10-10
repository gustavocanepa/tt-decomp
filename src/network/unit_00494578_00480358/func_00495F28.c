#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004967F8();                                /* extern */

extern char D_00495FA0[];
s32 func_00495F28(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x27;
    case 18:
    case 41:
        *arg0 = (s32)D_00495FA0;
        return 0x28;
    default:
        return func_004967F8();
    }
}
