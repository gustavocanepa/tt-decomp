#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" f32 func_002FAA80(char *arg0, f32 *arg1)
{
    s32 i;
    f32 acc;
    f32 zero;
    f32 f0;
    char *q;
    char *p;

    acc = 0.0f;
    zero = acc;
    q = arg0 + 0x104;
    p = arg0 + 0x184;
    i = 1;
    do {
        f0 = *(f32 *)p;
        p += 0xF4;
        if (f0 < zero) {
            f0 = -f0;
        }
        i -= 1;
        acc += f0;
    } while (i >= 0);

    acc = acc * 0x1.0000000000000p-1f;
    *arg1 = (acc * 0x1.89374Cp-7f) + 0x1.999998p-2f;

    return *(f32 *)(q + 0x53C) * 0x1.0000000000000p-2f;
}
