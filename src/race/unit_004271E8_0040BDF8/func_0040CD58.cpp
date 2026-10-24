#include "types.h"

struct Global;
extern Global D_00585A30;

struct Info {
    char pad0[0x5];
    u8 f5;
    char pad6[0xA];
};

struct Obj {
    char pad0[0xF8];
    s64 id;
    char pad100[0x67];
    u8 f167;
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_0040CD58(Obj *self) {
    s64 id = self->id;
    if (id == -1) {
        return 1;
    }
    if (func_0040B980(&D_00585A30, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, &info);
    self->f167 = info.f5;
    return 1;
}
