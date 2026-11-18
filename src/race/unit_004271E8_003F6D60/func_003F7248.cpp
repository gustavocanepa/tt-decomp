#include "types.h"

struct Obj {
    char pad[8];
    s32 unk8;
};

extern char D_00769548[];

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003F7248(Obj *arg0) {
    func_004AC378(D_00769548, arg0->unk8);
}
