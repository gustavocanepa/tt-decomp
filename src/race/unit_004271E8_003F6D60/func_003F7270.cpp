#include "types.h"

struct Self { s32 m0; s32 m4; s32 m8; };
extern char D_00769548[];
extern "C" s32 func_004AC3B8(char *, s32, s32);

extern "C" void func_003F7270(Self *self, s32 x) {
    s32 v = func_004AC3B8(D_00769548, x, 0);
    self->m4 = self->m8;
    self->m8 = v;
}
