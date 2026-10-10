#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_002E64C8(s8 *arg0, s32 arg1, f32 fparg0) {
    f32 t = fparg0 + *(f32 *)(arg0 + 0x574);
    f32 a = *(f32 *)(arg0 + arg1 * 4 + 0x95C);
    s8 *e = arg0 + arg1 * 0xF4;
    return a * t + *(f32 *)(e + 0x168) * (1.0f - t);
}
