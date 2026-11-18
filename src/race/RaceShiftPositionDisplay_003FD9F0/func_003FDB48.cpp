#include "types.h"

extern char D_007695D8[];

struct Obj {
    char pad[4436];
    s32 unk4;
};

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FDB48(struct Obj *arg0) {
    func_004AC378(D_007695D8, arg0->unk4);
}
