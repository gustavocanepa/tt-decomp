#include "types.h"

struct Obj {
    char pad[0x10B0];
    s32 unk10B0;
};

extern char D_007695A8[];

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FD4E8(struct Obj *arg0) {
    func_004AC378(D_007695A8, arg0->unk10B0);
}
