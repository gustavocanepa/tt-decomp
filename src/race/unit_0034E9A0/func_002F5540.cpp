#include "types.h"

void func_002F5540(void *arg0) {
    f32 k = 0x1.111110p-6f;
    f32 *v = (f32 *)((char *)arg0 + 0x658);
    f32 t0 = *(f32 *)((char *)arg0 + 0x5A8);
    f32 t3 = *v;
    f32 *q = (f32 *)((char *)arg0 + 0x65C);
    f32 temp_f1 = *q;
    f32 temp_f1_2;
    f32 s;

    temp_f1_2 = temp_f1 + ((((t0 - t3) * 500.0f) - (temp_f1 * 20.0f)) * k);
    *q = temp_f1_2;
    s = temp_f1_2 * k;
    *v = *v + s;
}
