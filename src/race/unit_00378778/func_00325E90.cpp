#include "types.h"

struct Obj {
    char pad0[0xE8];
    s32 unkE8;
    s32 unkEC;
    char padF0[0x58];
    s32 unk148;
    char pad14C[0x34];
    s32 unk180;
    s32 unk184;
};

struct Src {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_00321898(Obj *, Src *);

extern "C" void func_00325E90(Obj *p, Src *src) {
    func_00321898(p, src);
    p->unk148 = 4;
    p->unk184 = 0;
    p->unk180 = src->unk10;
    p->unkE8 = 0;
    p->unkEC = 0;
}
