#include "types.h"

/* Looks up a record by its 64-bit id through SPEC_DATABASE__DatabaseStorage__getRow (the manager D_00585A30) and returns
   one byte of it, or -1 when the id is unset. */
struct Info { u8 pad[0x2]; u8 field; u8 pad2[0xD]; };
struct Self { char pad[0xE8]; s64 id; };
extern char D_00585A30[];
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(char *, s64, Info *);

extern "C" s32 func_0040E0C8(Self *self) {
    Info info;
    if (self->id == -1) return -1;
    SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, self->id, &info);
    return info.field;
}
