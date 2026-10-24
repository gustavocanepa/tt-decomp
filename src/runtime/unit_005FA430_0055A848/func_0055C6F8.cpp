#include "types.h"

struct Obj {
    char pad0[0x80];
    s32 unk80;
    char pad84[0x24];
    s32 unkA8;
    s32 unkAC;
};

extern "C" Obj *func_0055BD30(void *);

extern "C" Obj *func_0055C6F8(void *self, s32 a, s32 b) {
    Obj *p = func_0055BD30(self);
    if (p != 0) {
        p->unkAC = b;
        p->unkA8 = a;
        p->unk80 = 0;
    }
    return p;
}
