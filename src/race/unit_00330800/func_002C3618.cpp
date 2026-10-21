#include "types.h"

struct Obj {
    s32 a;
    s32 h;
    s32 pad[2];
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 bpp;
};

extern "C" void func_002C3480(s32, s32, s32, s32, s32);

extern "C" void func_002C3618(Obj *o) {
    func_002C3480(o->h, o->w * o->bpp, o->x, o->y * o->z, 0x10);
}
