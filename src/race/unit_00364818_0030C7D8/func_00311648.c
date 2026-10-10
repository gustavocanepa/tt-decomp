#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { u8 pad[0x51A]; s16 a; f32 b; } T;
void func_00311648(s8 *arg0) {
    T *p = (T *)(arg0 + 0x104);
    p->a = p->b * 60.0f / 0x1.921FB4p+2f;
}
