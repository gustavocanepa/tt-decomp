#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[0x51A]; s16 a; f32 b; } T;
void func_002F5748(s8 *arg0) {
    T *q = (T *)(arg0 + 0x104);
    s32 v = q->b * 60.0f / 0x1.921FB4p+2f;
    s8 *s = *(s8 **)(arg0 + 0x10);
    s32 n = *(u16 *)(s + 0x20E) - 1;
    if (*(u8 *)(s + 0x252) == 4) {
        if (v < 0) v = 0;
        q->a = v;
    } else {
        if (v < n) v = n;
        q->a = v;
    }
}
