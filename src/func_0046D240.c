#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046D0F8(f32, f32, f32);               /* extern */

extern char D_0076E850[];
void func_0046D240(f32 fparg0, f32 fparg1, f32 fparg2) {
    func_0046D0F8(fparg0 - *(f32 *)(f32 *)D_0076E850, fparg1 - *(f32 *)((s32)D_0076E850 + 4), fparg2 - *(f32 *)((s32)D_0076E850 + 8));
}
