typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *self);
};

struct Target {
    char pad0[0x5C];
    VEntry *vtbl;
};

struct Obj {
    Target *target;
};

extern "C" void func_0044B290(void *ctx, void *arg);
extern "C" void func_004477D0(Target *target, void *arg);

extern "C" void func_00442728(Obj *self, void *arg) {
    Target *t = self->target;
    VEntry *e = &t->vtbl[3];
    func_0044B290(e->fn((char *)t + e->delta), arg);
    func_004477D0(self->target, arg);
}
