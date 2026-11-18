#include "types.h"

struct Event {
    char pad0[0x20];
    s32 button;
    s32 state;
    char pad_near28[4];
    f32 x;
    f32 y;
};

extern "C" void func_0022F878(Event *self);
extern char D_005EE778[]; /* "button %d state %04x port %d x %d y %d " */
extern "C" void func_00526860(const char *fmt, ...);

extern "C" s32 func_0024F248(Event *self) {
    func_0022F878(self);
    func_00526860(D_005EE778, self->button, self->state,
                  self->state & 0xF, (s32)self->x, (s32)self->y);
    return 0;
}
