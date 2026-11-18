extern "C" void func_001035A0(void);
extern "C" void func_004A4D68(void *a0);
extern "C" void func_004A4DD8(void *a0);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[0x64];
    VEntry *vt;
    char pad68[0x4];
    char lock[0x38];
    int refs;
};

extern "C" void func_00109768(Obj *self) {
    char *lock = self->lock;
    func_004A4D68(lock);
    int flag = 0;
    int r = self->refs + 1;
    self->refs = r;
    if (r == 1) {
        flag = 1;
        VEntry *e = &self->vt[19];
        e->fn((char *)self + e->delta);
    }
    func_004A4DD8(lock);
    if (flag) {
        func_001035A0();
    }
}
