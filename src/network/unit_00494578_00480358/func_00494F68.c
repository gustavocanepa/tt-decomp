#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004967F8();                                /* extern */

extern char D_00494FF8[];
extern char D_00495050[];
s32 func_00494F68(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0xB;
    case 22:
        *arg0 = (s32)D_00494FF8;
        return 0xB;
    case 18:
        *arg0 = (s32)D_00495050;
        return 9;
    default:
        return func_004967F8();
    }
}
