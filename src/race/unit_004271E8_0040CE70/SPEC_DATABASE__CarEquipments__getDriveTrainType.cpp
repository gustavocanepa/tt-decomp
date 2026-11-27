#include "types.h"

/* the record SPEC_DATABASE__DatabaseStorage__getRow fills for an id */
struct Info {
    char pad0[0x10];
    u8 f10;
    char pad11[0xF];
};

struct Global;

struct Obj {
    char pad0[0x40];
    s64 id;
};

extern Global D_00585A30;

extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);

extern "C" s32 SPEC_DATABASE__CarEquipments__getDriveTrainType(Obj *self) {
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, self->id, &info);
    return info.f10;
}
