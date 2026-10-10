/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B44E0(f32);                         /* extern */

void func_00505480(f32 fparg0) {
    func_004B44E0(0x1.1940000000000p+27f / fparg0);
}
