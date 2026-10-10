/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003DD798();                            /* extern */
s32 func_003DD8C8(s32, s32);                    /* extern */

void func_003DDED8(s32 arg0, s32 arg1) {
    func_003DD798();
    func_003DD8C8(arg0, arg1);
}
