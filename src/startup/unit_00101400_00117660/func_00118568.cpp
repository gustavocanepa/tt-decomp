#include "types.h"

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" int func_00118558(void) throw();

extern "C" void func_00118568(struct Obj *arg0) {
    s32 temp_v0 = arg0->unk8;

    if (temp_v0 == 0) {
        func_00118558();
    }
}
