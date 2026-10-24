#include "types.h"

struct Obj003685A0 {
    unsigned char pad0[0x540];
    unsigned char flag520;
};

f32 func_00310718(struct Obj003685A0 *arg0, f32 fparg0, f32 fparg1) {
    f32 t = fparg1;
    f32 u;

    if (arg0->flag520 == 0) {
        t = -t;
    }
    if (t <= 0x1.0AAAA8p+2f) {
        return fparg0;
    }
    u = (0x1.0AAAA8p+2f - t) / 0x1.0AAAA8p+2f;
    if (0.0f < u) {
        u = 0.0f;
    }
    if (u < -0x1.0000000p+0f) {
        u = -0x1.0000000p+0f;
    }
    u = u * 0x1.999998p-1f;
    return u + (1.0f - u) * fparg0;
}
