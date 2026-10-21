#include "types.h"

struct Obj {
    char pad[0x124];
    s32 unk124;
};

extern "C" void *func_001803E8(void *);
extern "C" void func_00180390(void *, s32);

extern "C" void func_001819C8(void) {
    Obj *tmp[4];

    func_001803E8(tmp);
    tmp[0]->unk124 = 0;
    func_00180390(tmp, 2);
}
