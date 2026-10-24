#include "types.h"

struct Obj {
    char pad0[0x698];
    s32 unk698;
};

extern "C" void func_004A4D68(Obj *self);
extern "C" void func_004A4DD8(Obj *self);

extern "C" void func_00198940(Obj *self, s32 value) {
    func_004A4D68(self);
    self->unk698 = value;
    func_004A4DD8(self);
}
