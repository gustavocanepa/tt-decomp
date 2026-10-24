#include "types.h"

struct Quat { f32 x, y, z, w; };
extern "C" void func_004A6328(f32, f32 *, f32 *);

extern "C" void func_00451890(Quat *q, f32 angle) {
    f32 s, c;
    func_004A6328(angle * 0.5f, &s, &c);
    q->x = s;
    q->y = 0.0f;
    q->z = 0.0f;
    q->w = c;
}
