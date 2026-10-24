#include "types.h"

extern "C" void *D_005DA100;
extern "C" void func_00455BA8(void *arg0);

struct Obj {
    char pad[0x18];
    s32 unk18;
    char pad2[0x24 - 0x18 - 4];
    void *unk24;
};

extern "C" void func_00455B20(Obj *arg0) {
    arg0->unk18 = 0;
    arg0->unk24 = &D_005DA100;
    return func_00455BA8(arg0);
}
