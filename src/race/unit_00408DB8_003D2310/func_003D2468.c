#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_003D23C0(f32);                             /* extern */
s32 func_003D7788(f32, f32);                    /* extern */

void func_003D2468(f32 fparg0, f32 fparg1) {
    func_003D7788(fparg0, func_003D23C0(fparg1));
}
