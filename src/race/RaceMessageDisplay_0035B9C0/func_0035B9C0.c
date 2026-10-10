/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomaticFader__update(s32);                         /* extern */
s32 Oscillator__update(s32, f32);                    /* extern */

void func_0035B9C0(s32 arg0, f32 fparg0) {
    AutomaticFader__update(arg0 + 0x2C);
    Oscillator__update(arg0 + 0x48, fparg0);
}
