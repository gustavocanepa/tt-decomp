extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, int);
};

struct Obj {
    char pad0[0x64];
    VEntry *vt;
    char pad68[0x4];
    char lock[0x38];
    int refs;
};

extern "C" void func_00109650(Obj *self, int arg)
{
    func_004A4D68(self->lock);
    if (self->refs < 2) {
        VEntry *e = &self->vt[18];
        e->fn((char *)self + e->delta, arg);
    }
    func_004A4DD8(self->lock);
}
