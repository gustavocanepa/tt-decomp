#include "types.h"

struct Vec2 {
    f32 x;
    f32 y;
};

struct Param {
    char pad0[0x90];
    Vec2 pos;
};

struct Obj {
    char pad0[0x28];
    Param *cur;
};

extern "C" void func_0043D200(Obj *self, f32 x, f32 y);
extern "C" void func_0043C348(Obj *self);

extern "C" void func_0043C4C0(Obj *self, Param *p) {
    Vec2 *v = &p->pos;
    if (self->cur != p) {
        self->cur = p;
        func_0043D200(self, v->x, v->y);
        func_0043C348(self);
    }
}
