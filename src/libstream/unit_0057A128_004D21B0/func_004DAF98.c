/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004DAAA0();                                /* extern */
s32 func_004DAB58();                                /* extern */
s32 func_004DAF00(s32, s32);                    /* extern */

void func_004DAF98(s32 arg0) {
    s32 temp_s1;

    s32 t;
    temp_s1 = func_004DAAA0();
    t = func_004DAB58() * 0x3C - 0x21C;
    func_004DAF00(arg0, temp_s1 + t);
}
