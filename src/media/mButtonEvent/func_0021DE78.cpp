typedef unsigned short u16;
typedef int s32;
typedef float f32;

struct Event {
    char pad0[0x20];
    u16 button;
    u16 pad22;
    s32 state;
    f32 x;
    f32 y;
};

extern "C" void func_0022F878(Event *self);
extern char D_005EC508[]; /* "button %d state %04x port %d x %d y %d " */
extern "C" void func_00526860(const char *fmt, ...);

extern "C" s32 func_0021DE78(Event *self) {
    func_0022F878(self);
    func_00526860(D_005EC508, self->button, self->state,
                  self->state & 0xF, (s32)self->x, (s32)self->y);
    return 0;
}
