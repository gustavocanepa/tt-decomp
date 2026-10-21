#include "types.h"

struct Obj {
    char pad[0x4];
    u32 *unk4;
};

extern "C" void func_00476DD8(Obj *arg0) {
    u32 *temp_v1 = arg0->unk4;
    *temp_v1 |= 0x8000;
}
