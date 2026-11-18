#include "types.h"
u8 *func_003D8FB8(u8 *arg0, f32 fparg0) {
    f32 v = fparg0;
    u8 *s = (u8 *)&v;
    u32 i;
    for (i = 0; i < 4; i++) *arg0++ = *s++;
    return arg0;
}
