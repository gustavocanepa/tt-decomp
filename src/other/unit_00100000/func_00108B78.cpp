typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[0x5C];
    int pending;
    int pad60;
    VEntry *vtbl;
};

extern "C" void func_004A4D68(Obj *self);
extern "C" void func_004A4DD8(Obj *self);
extern "C" void func_004A4F00(Obj *self);

extern "C" void func_00108B78(Obj *self) {
    func_004A4D68(self);
    if (self->pending) {
        self->pending = 0;
        VEntry *e = &self->vtbl[11];
        e->fn((char *)self + e->delta);
        func_004A4F00(self);
    }
    func_004A4DD8(self);
}
