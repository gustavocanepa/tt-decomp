/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0042DC88();                                /* extern */
f32 SystemSoundGetOutputModeVolume(s32, s32);                    /* extern */
s32 func_004B57A8(f32);                         /* extern */

void func_0042B3C0(f32 fparg0) {
    func_004B57A8(fparg0 * SystemSoundGetOutputModeVolume(func_0042DC88(), 4));
}
