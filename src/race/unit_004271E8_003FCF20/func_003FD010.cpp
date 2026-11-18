#include "types.h"

struct Obj {
    char pad[0x12];
    u8 unk12;
};

extern char D_00769580[];

extern "C" void func_004AC378(void *arg0, u8 arg1);

extern "C" void func_003FD010(struct Obj *arg0) {
    func_004AC378(D_00769580, arg0->unk12);
}
