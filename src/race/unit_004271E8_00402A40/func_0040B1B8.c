/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040B1F0(s32);                         /* extern */
s32 func_0040BA60(s32, s32);                    /* extern */
s32 func_0040BAE0();                                /* extern */

void func_0040B1B8(s32 arg0) {
    func_0040BA60(arg0, func_0040BAE0());
    func_0040B1F0(arg0);
}
