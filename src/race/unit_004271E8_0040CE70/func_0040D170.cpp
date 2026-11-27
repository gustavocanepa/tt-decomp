#include "types.h"

struct Info { char pad[9]; u8 m9; char pad2[0x16]; };
struct Self { char pad[0xB0]; s64 id; };
extern char D_00585A30[];
extern "C" void SPEC_DATABASE__DatabaseStorage__getRow(char *, s64, Info *);

extern "C" s32 func_0040D170(Self *self) {
    Info info;
    if (self->id == -1) return 0;
    SPEC_DATABASE__DatabaseStorage__getRow(D_00585A30, self->id, &info);
    return info.m9 != 0;
}
