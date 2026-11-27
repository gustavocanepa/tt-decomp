extern "C" void func_001D05D0(void);
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Sub {
    int pad0;
    char *vt;
};

struct Obj {
    char pad0[0x70];
    Sub *sub;
    char lock[8];
};

extern "C" void func_00108D68(Obj *self)
{
    func_004A4D68(self->lock);
    if (self->sub != 0) {
        func_001D05D0();
        Sub *s = self->sub;
        VEntry *e = (VEntry *)(s->vt + 0x238);
        e->fn((char *)s + e->delta);
    }
    func_004A4DD8(self->lock);
}
