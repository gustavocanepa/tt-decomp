#include "types.h"

struct Obj {
    char pad[0x1114];
    s32 unk1114;
};

extern char D_007695B8[];

extern "C" void func_004AC378(void *arg0, s32 arg1);

extern "C" void func_003FD968(struct Obj *arg0) {
    func_004AC378(D_007695B8, arg0->unk1114);
}
