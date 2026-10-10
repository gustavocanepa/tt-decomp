#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { u8 pad[0x4B4]; f32 c; u8 pad2[0x508 - 0x4B8]; f32 a; f32 b; u8 pad3[0x51A - 0x510]; s16 n; } T;
extern f32 D_00767384;
f32 func_002F9DE8(s8 *arg0) {
    T *q = (T *)(arg0 + 0x104);
    f32 x = (q->a + q->b) * q->n * 0x1.B7860Ep-14f;
    f32 r = q->c / (x / (x + D_00767384 + D_00767384));
    if (1.0f < r) r = 1.0f;
    return r;
}
