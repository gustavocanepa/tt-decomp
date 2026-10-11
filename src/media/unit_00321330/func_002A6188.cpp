struct Tmp {
    int pad[4];
    Tmp() __asm__("func_002A7A30");
    ~Tmp() __asm__("func_002A75A8");
};

struct Target;

struct VEntry {
    short delta;
    short pad;
    void (*fn)(Target *self, int a, Tmp *t);
};

struct Target {
    int x;
    VEntry *vtbl;
};

struct Handle {
    Target *p;
    int pad[3];
    Handle() __asm__("func_002BC270");
    ~Handle() __asm__("func_002BC0E0");
};

extern "C" void func_002A6108(void *self, Handle *h, int key);

extern "C" void func_002A6188(void *self, int a, int key)
{
    Handle h;
    func_002A6108(self, &h, key);
    if (h.p != 0) {
        VEntry *e = &h.p->vtbl[9];
        Target *t = (Target *)((char *)h.p + e->delta);
        Tmp tmp;
        e->fn(t, a, &tmp);
    }
}
