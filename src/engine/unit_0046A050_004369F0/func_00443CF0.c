/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00443D50();                                /* extern */
s32 func_00443D98(s32, s32);                /* extern */
s32 func_00443DD0(s32, s32);                /* extern */

void func_00443CF0(s32 arg0, s32 arg1) {
    if (func_00443D50() != arg1) {
        if (arg1 != 0) {
            func_00443D98(arg0, 1);
            return;
        }
        func_00443DD0(arg0, 1);
    }
}
