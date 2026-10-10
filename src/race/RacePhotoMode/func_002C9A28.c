/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C9998();                                /* extern */
s32 func_002F0198(s32, f32);                    /* extern */

void func_002C9A28(f32 fparg0) {
    func_002F0198(func_002C9998(), fparg0);
}
