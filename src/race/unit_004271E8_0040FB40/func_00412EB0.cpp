#include "types.h"

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char unk10[0x30];
    void *unk40;
};

extern char D_005D9878[];

extern "C" void *func_004AE9C0(void *p);

extern "C" void func_00412EB0(Obj *self) {
    self->unk40 = D_005D9878;
    func_004AE9C0(self->unk10);
    self->unk0 = -1;
    self->unk4 = -1;
    self->unk8 = -1;
    self->unkC = 0;
}
