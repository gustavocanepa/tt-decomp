#include "types.h"

extern char D_00769548[];

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003F7220(struct Obj *arg0) {
    func_004AC378(D_00769548, arg0->unk4);
}
