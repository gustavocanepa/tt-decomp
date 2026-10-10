#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00301F08();                                /* extern */
s32 func_00301F68(s32);                         /* extern */

void func_00302620(s32 arg0) {
    if (func_00301F08() != 0) {
        func_00301F68(arg0);
    }
}
