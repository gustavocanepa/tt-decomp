extern "C" void func_0026CD80(void *);
extern "C" void func_0026CD28(void *, int);
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);

struct Lock {
    void *const m;
    Lock(void *mutex) : m(mutex) { func_004A4D68(m); }
    ~Lock() { func_004A4DD8(m); }
};

struct Range {
    int first;
    int last;
    int end;
};

struct Pool {
    char pad0[0x10];
    Range range;
    char pad1c[0x104];
    char mutex[0x10];
};

struct Handle {
    Pool *p;
    int pad[3];
};

extern "C" void func_0026D318(void)
{
    Handle h;
    func_0026CD80(&h);
    {
        Pool *p = h.p;
        Range *r = &p->range;
        Lock lock(p->mutex);
        r->first = 0;
        r->last = 0;
        r->end = 0;
    }
    func_0026CD28(&h, 2);
}
