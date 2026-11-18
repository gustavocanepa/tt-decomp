/* compiler: ee-gcc2.96-nogcse */
typedef int s32;

struct Dim {
    char pad0[0xC];
    s32 w;
    s32 h;
};

struct Obj {
    s32 p0;
    s32 p4;
    s32 p8;
    char padC[0x80 - 0xC];
    s32 p80;
    char pad84[0xE4 - 0x84];
    s32 pB4;
    Dim d;
    char padD8[0x108 - 0xE8 - sizeof(Dim)];
    s32 pD8;
};

extern "C" void func_00104A48(s32, s32, s32);
extern "C" s32 func_00104B10(s32);
extern "C" void func_00472268(s32, s32);
extern "C" void func_00472628(void);
extern "C" void func_00472AE8(s32, s32, s32, s32, s32, s32, s32, s32);

extern "C" void func_001B2538(Obj *self) {
    if (self->pB4 != 0) {
        Dim *d = (Dim *)((char *)self + 0xE8);
        s32 y = 0;
        s32 addr;
        func_00104A48((s32)self, d->w, d->h);
        self->p4 = 0;
        func_00104B10((s32)self);
        self->p80 = 1;
        addr = self->pD8;
        for (; y < d->h; y += 0x10) {
            s32 x;
            for (x = 0; x < d->w; x += 0x10) {
                func_00472AE8(self->p0, self->p4, (self->p8 + 0x3F) & ~0x3F, x, y, 0x10, 0x10, addr);
                addr += 0x400;
            }
        }
        func_00472628();
        func_00472268(2, 1);
        func_00472268(3, 1);
    }
}
