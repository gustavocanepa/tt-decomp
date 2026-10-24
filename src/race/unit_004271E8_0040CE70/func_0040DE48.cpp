#include "types.h"

struct Obj {
    char pad[0x48];
    s64 key;
};

struct Rec {
    char pad[0x22];
    u8 value;
    char tail[0x15];
};

extern char D_00585A30[];
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(void *, s64, void *);

extern "C" s32 func_0040DE48(Obj *self) {
    Rec rec;
    if (self->key == -1)
        return -1;
    SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, self->key, &rec);
    return rec.value;
}
