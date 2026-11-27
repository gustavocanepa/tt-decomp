#include "types.h"

struct Vec {
    f32 x, y, z, w;
};

extern Vec D_005FFEB0;
extern "C" void func_00473050(void);
extern "C" void func_004757FC(void);
extern "C" void func_00475850(Vec *out, const Vec *in);
extern "C" void func_004730A8(void);

extern "C" bool func_0041D2E8(void) {
    Vec v;
    func_00473050();
    func_004757FC();
    func_00475850(&v, &D_005FFEB0);
    func_004730A8();
    return v.x <= 0.0f;
}
