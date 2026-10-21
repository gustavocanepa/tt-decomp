#include "types.h"

extern char D_007695C8[];

struct Obj {
    char pad[4384];
    s32 unk4;
};

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FDA88(struct Obj *arg0) {
    func_004AC378(D_007695C8, arg0->unk4);
}
