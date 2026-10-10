#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { f32 x; u8 pad[0xF0]; } E;
typedef struct { u8 pad[0x208]; E e[7]; u8 pad2[0xD8]; f32 f[1]; } T;
f32 func_003A0AA8(T *arg0, s32 arg1, f32 fparg0) {
    f32 a = arg0->f[arg1];
    E *e = &arg0->e[arg1]; f32 b = e->x;
    {
    f32 temp_f0 = (a - b) * fparg0 + b;
    return temp_f0 * temp_f0;
    }
}
