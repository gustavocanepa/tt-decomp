/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040AF60(s32, s32);                    /* extern */
s32 func_0040BAE0();                                /* extern */

void func_0040AF30(s32 arg0) {
    func_0040AF60(arg0, func_0040BAE0());
}
