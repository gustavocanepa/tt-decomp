#include "types.h"

struct Obj {
    char pad0[0x14];
    void *unk14;
};

extern "C" s32 func_00408B58(void *arg0);
extern "C" s32 func_0040D360(s32 arg0);

extern "C" void func_00131710(Obj *arg0) {
    func_0040D360(func_00408B58(arg0->unk14));
}
