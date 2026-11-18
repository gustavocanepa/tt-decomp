#include "types.h"

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" f32 func_002E5E40(void *ctx, f32 angle);
extern "C" f32 func_002E5EA0(void *ctx, f32 angle);
extern "C" f32 func_002E5ED0(void *ctx, f32 angle);
extern "C" s32 func_00469340(const Vec3 *a, const Vec3 *b);

extern "C" s32 func_002D3410(void *ctx, f32 angle) {
    Vec3 low;
    Vec3 high;
    f32 t1, t2, t3;

    t1 = func_002E5E40(ctx, angle);
    t2 = func_002E5EA0(ctx, angle);
    t3 = func_002E5ED0(ctx, angle);
    low.x = t1 - 4.0f;
    low.y = t2 - 4.0f;
    low.z = t3 - 4.0f;
    high.x = t1 + 4.0f;
    high.y = t2 + 4.0f;
    high.z = t3 + 4.0f;
    return func_00469340(&low, &high) != 0;
}
