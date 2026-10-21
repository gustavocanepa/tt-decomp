#include "types.h"

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x6];
    u8 f6;
    char pad7[0x2];
    u8 f9;
    char padA[0x6];
};

struct Obj {
    char pad0[0xE8];
    s64 id;
    char padF0[0x66];
    u8 f156;
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" u8 func_0040CDD0(Obj *self, s32 a, s32 b, s32 c);

extern "C" s32 func_0040CCC8(Obj *self) {
    s64 id = self->id;
    if (func_0040B980(&D_00585A30, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, &info);
    self->f156 = func_0040CDD0(self, 1, info.f9, info.f6);
    return 1;
}
