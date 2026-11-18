#include "types.h"

struct Obj {
    char pad[0x11];
    u8 unk11;
};

extern char D_00769578[];

extern "C" void func_004AC378(void *arg0, u8 arg1);

extern "C" void func_003FCFB0(struct Obj *arg0) {
    func_004AC378(D_00769578, arg0->unk11);
}
