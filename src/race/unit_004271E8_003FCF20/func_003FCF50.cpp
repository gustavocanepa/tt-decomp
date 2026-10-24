#include "types.h"

struct Obj {
    char pad[0x10];
    u8 unk10;
};

extern char D_00769570[];

extern "C" void func_004AC378(void *arg0, u8 arg1);

extern "C" void func_003FCF50(struct Obj *arg0) {
    func_004AC378(D_00769570, arg0->unk10);
}
