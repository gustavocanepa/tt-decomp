#include "types.h"

struct Obj {
    char pad[0x20];
    s32 unk20;
};

extern char D_007695A0[];

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FD488(struct Obj *arg0) {
    func_004AC378(D_007695A0, arg0->unk20);
}
