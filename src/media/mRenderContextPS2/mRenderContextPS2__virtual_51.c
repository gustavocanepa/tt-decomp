/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E49C8();                                /* extern */
s32 func_00467D10(s32, f32, f32, f32, f32);     /* extern */

void mRenderContextPS2__virtual_51(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    func_00467D10(func_001E49C8(), fparg0, fparg1, fparg2, fparg3);
}
