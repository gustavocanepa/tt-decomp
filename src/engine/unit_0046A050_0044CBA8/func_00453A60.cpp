#include "types.h"

struct Vec2 {
    f32 x, y;
    Vec2() {}
    Vec2(const Vec2 &o) : x(o.x), y(o.y) {}
    Vec2 &operator=(const Vec2 &o) { x = o.x; y = o.y; return *this; }
};

extern "C" Vec2 func_00453A18(s32, const Vec2 &);

extern "C" void func_00453A60(Vec2 *self, s32 arg1) {
    *self = func_00453A18(arg1, *self);
}
