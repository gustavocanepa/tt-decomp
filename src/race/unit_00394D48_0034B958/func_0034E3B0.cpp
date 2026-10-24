#include "types.h"

struct Vec3 {
    f32 x, y, z;
};

typedef int s32;

extern "C" void func_0034E420(s32 arg0, struct Vec3 *arg1);
extern "C" void func_0041C2A0(f32 arg0, f32 arg1, f32 arg2);

extern "C" void func_0034E3B0(s32 arg0) {
    struct Vec3 v;
    func_0034E420(arg0, &v);
    func_0041C2A0(v.x, v.y, v.z);
}
