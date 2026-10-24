#include "types.h"

extern char D_005D9830;

struct Obj {
    s32 unk0;
    s32 unk4;
    void *unk8;
};

extern "C" void func_00411C18(Obj *arg0) {
    arg0->unk4 = -1;
    arg0->unk8 = &D_005D9830;
    arg0->unk0 = 0;
}
