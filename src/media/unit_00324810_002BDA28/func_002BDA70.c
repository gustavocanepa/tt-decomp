#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002BD918();                            /* extern */
s32 func_004A45D0();                            /* extern */

void func_002BDA70(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        if (arg2 == 4) {
            func_002BD918();
            return;
        }
        func_004A45D0();
    }
}
