#include "types.h"

struct Vec3 {
    f32 x, y, z;
};

extern Vec3 D_00584088;
extern f32 D_00584094;
extern "C" void func_00471CB0(f32, f32, f32);

extern "C" void func_0034DD00(void) {
    f32 s = D_00584094;
    func_00471CB0(D_00584088.x * s, D_00584088.y * s, D_00584088.z * s);
}
