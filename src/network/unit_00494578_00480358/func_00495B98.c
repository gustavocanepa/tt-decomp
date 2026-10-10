#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004967F8();                                /* extern */

extern char D_00495B18[];
extern char D_00495D68[];
s32 func_00495B98(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 0x21;
    case 24:
        *arg0 = (s32)D_00495D68;
        return 0x21;
    case 21:
        *arg0 = (s32)D_00495B18;
        return 0x21;
    default:
        return func_004967F8();
    }
}
