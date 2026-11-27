#include "types.h"

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x104];
    Vec4 unk104;
};

extern "C" void func_00391890(Vec4 *arg0);

extern "C" void func_0035D488(struct Obj *arg0) {
    func_00391890(&arg0->unk104);
}
