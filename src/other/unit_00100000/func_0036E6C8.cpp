typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    char pad0[0x8];
    u8 active;
    char pad9[0x3];
    u32 state;
};

extern "C" void func_0036E708(Obj *self);

extern "C" void func_0036E6C8(Obj *self) {
    if (self->active && self->state < 2) {
        func_0036E708(self);
    }
}
