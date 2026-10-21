#include "types.h"

struct Info {
    s32 unk0[2];
    s32 unk8;
    char padC[0x74];
};

struct Global {
    char pad0[0x1E8];
    s32 unk1E0;
};

struct Obj {
    char pad0[0x38];
    s64 id;
};

extern Global D_00585A30;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" void func_00411D78(s32 a, s32 b);

extern "C" void func_0040DCA0(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, self->id, &info);
    func_00411D78(D_00585A30.unk1E0, info.unk8);
}
