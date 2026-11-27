#include "types.h"

struct Vec4 {
    f32 x, y, z, w;
};

Vec4 *func_00532380(Vec4 *arg0, Vec4 *arg1, Vec4 *arg2) {
    Vec4 *dst = arg2;
    while (arg0 != arg1) {
        if (dst != 0) {
            dst->x = arg0->x;
            dst->y = arg0->y;
            dst->z = arg0->z;
            dst->w = arg0->w;
        }
        arg0++;
        dst++;
    }
    return dst;
}
