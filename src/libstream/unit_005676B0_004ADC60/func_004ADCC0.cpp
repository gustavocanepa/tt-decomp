#include "types.h"

struct Obj {
    char pad0[4];
    u32 unk4;
};

extern "C" void func_004ADCC0(Obj *arg0, Obj *arg1, Obj *arg2) {
    u32 temp_v1 = arg2->unk4;
    arg1->unk4 = temp_v1;
    if (temp_v1 < arg0->unk4) {
        *(void **)temp_v1 = arg1;
    }
}
