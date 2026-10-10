extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    VEntry *vt;
    char pad68[0x4];
    char lock[0x38];
    int refs;
};

extern "C" void func_001097F0(Obj *self)
{
    func_004A4D68(self->lock);
    if (self->refs != 0) {
        if (--self->refs == 0) {
            VEntry *e = &self->vt[20];
            e->fn((char *)self + e->delta);
        }
    }
    func_004A4DD8(self->lock);
}
