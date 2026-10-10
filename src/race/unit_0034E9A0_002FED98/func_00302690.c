#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00301F08();                                /* extern */
s32 func_00301F88(s32, s32, s32);       /* extern */

void func_00302690(s32 arg0) {
    if (func_00301F08() != 0) {
        func_00301F88(arg0, 9, -1);
    }
}
