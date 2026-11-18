#include "types.h"

struct Obj {
    char pad0[0xBC8];
    s32 fBC8;
    s32 fBCC;
};

extern "C" s32 func_003ED008(Obj *arg0) {
    Obj *self;
    s32 a3;
    s32 a1;
    s32 v1;
    s32 t;
    char *w;

    self = arg0;
    a3 = self->fBCC;
    a1 = a3 + 1;
    if (a1 >= 2) {
        a1 = 0;
    }
    if (*(u8 *)((char *)self + a1 * 0x2B8 + 0x900) == 0) {
        return 0;
    }
    v1 = self->fBC8;
    self->fBCC = a1;
    self->fBC8 = a3;
    if (v1 >= 0) {
        t = v1 * 0x2B8;
        t = t + 0x8F0;
        w = (char *)self + t;
        *(s32 *)(w + 0x10) = (s32)((unsigned)*(s32 *)(w + 0x10) & 0xFFFFFF00);
    }
    return 1;
}
