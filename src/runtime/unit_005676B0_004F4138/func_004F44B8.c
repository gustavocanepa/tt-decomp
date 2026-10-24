#include "types.h"
extern char D_005DB6A0[];
struct Obj { s32 f0; char pad4[0x28]; s32 f2C; s32 f30; s32 f34; char *f38; };
s32 func_004F4138(s32, s32);

void func_004F44B8(struct Obj *o) {
    o->f38 = D_005DB6A0;
    o->f0 = func_004F4138(1, 1);
    o->f2C = 0;
    o->f30 = 0;
    o->f34 = 0;
}
