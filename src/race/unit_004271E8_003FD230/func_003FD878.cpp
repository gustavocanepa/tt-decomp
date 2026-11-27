#include "types.h"

extern char D_007695B0[];

struct Obj {
    char pad[4404];
    s32 unk4;
};

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FD878(struct Obj *arg0) {
    func_004AC378(D_007695B0, arg0->unk4);
}
