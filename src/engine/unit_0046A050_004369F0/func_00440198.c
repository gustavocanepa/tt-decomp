#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct { s32 a; s32 b; } S;
typedef struct { u8 pad[0x2C]; S s; } E;
extern char D_006016C0[];
void *func_00440198(void **p) {
    void *r = D_006016C0;
    S *s = &M2C_FIELD(p[0], E **, 0x60)[M2C_FIELD(p[1], s16 *, 6)].s;
    if (s->b != 0) r = (void *)s->a;
    return r;
}
