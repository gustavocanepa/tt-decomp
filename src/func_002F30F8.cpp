#include "types.h"

struct func_002F30F8_arg0 {
    char pad0[0xDB];
    u8 flag;      /* 0xDB */
    f32 d;        /* 0xDC */
    f32 e;        /* 0xE0 */
};

f32 func_002F30F8(struct func_002F30F8_arg0 *arg0, f32 fparg0, f32 fparg1)
{
    f32 q;
    f32 t;
    f32 e;
    f32 d;
    f32 diff;

    if (arg0->flag == 0) {
        return fparg0;
    }
    e = arg0->e;
    t = fparg0 * fparg1;
    {
        f32 one = 1.0f;
        d = arg0->d;
        if (t <= d * (one - e)) {
            return fparg0;
        }
        q = d * (one - e * 0.5f);
    }
    if (!(d <= t)) {
        diff = d - t;
        q = q - (diff * diff) / ((e + e) * d);
    }
    q = q / fparg1;
    return (q < fparg0) ? q : fparg0;
}
