#include "types.h"

extern "C" void func_003EA148(f32 *arg0, f32 *arg1)
{
    int k = 4;
    int k2 = 8;
    f32 *p1 = (f32 *) (((char *) arg0) + k);
    f32 *p2 = (f32 *) (((char *) arg0) + k2);
    const f32 *q1 = (const f32 *) (((const char *) arg1) + k);
    const f32 *q2 = (const f32 *) (((const char *) arg1) + k2);

    arg0[12] = ((-arg0[0] * arg1[0]) - (arg0[4] * q1[0])) - (arg0[8] * q2[0]);
    arg0[13] = ((-p1[0] * arg1[0]) - (arg0[5] * q1[0])) - (arg0[9] * q2[0]);
    arg0[14] = ((-p2[0] * arg1[0]) - (arg0[6] * q1[0])) - (arg0[10] * q2[0]);
}
