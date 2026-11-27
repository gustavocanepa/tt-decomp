#include "types.h"

struct Obj {
    char pad[0x48];
    s32 unk48;
};

extern "C" void func_00481718(s32 arg0);

extern "C" void func_00481550(Obj *arg0) {
    s32 temp_v0 = arg0->unk48;
    if (temp_v0 != 0) {
        func_00481718(temp_v0);
    }
}
