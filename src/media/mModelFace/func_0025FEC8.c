/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001CDA78(s32, s32);                    /* extern */
s32 func_001CDAA8(s32, s32);                    /* extern */

void func_0025FEC8(s32 arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0xB4;
    func_001CDA78(temp_s1, arg0 + 0x344);
    func_001CDAA8(temp_s1, arg0 + 0x350);
}
