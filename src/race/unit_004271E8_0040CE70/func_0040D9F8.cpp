#include "types.h"

/* the record SPEC_DATABASE__DatabaseStorage__getRow fills for an id */
struct Info {
    char pad0[0x54];
    u16 f18;
    char pad1A[0x26];
};

struct Global;

struct Obj {
    char pad0[0x30];
    s64 id;
};

extern Global D_00585A30;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 func_0040D9F8(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, self->id, &info);
    return info.f18;
}
