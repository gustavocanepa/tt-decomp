/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceValueDisplayBase__update(s32);                         /* extern */
s32 Oscillator__update(s32);                         /* extern */
s32 func_0035F650(s32, f32);                    /* extern */

void RacePriusPanel__update(s32 arg0, f32 fparg0) {
    Oscillator__update(arg0 + 0x230);
    RaceValueDisplayBase__update(arg0 + 0x78);
    RaceValueDisplayBase__update(arg0 + 0xE4);
    func_0035F650(arg0 + 0x154, fparg0);
}
