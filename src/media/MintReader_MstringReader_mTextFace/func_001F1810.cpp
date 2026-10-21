typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Target {
    int m0;
    char *vtbl;
};

struct H {
    Target *p;
    int pad[3];
};

struct T {
    void *v;
    void *get() { return v; }
    int pad[3];
};

extern "C" void func_001F0C00(void *arg0, void *arg1);
extern "C" void func_001F0BA8(void *arg0, int arg1);
extern "C" void func_001B6F08(void *arg0, void *arg1);
extern "C" void func_001B6EB0(void *arg0, int arg1);

extern "C" void func_001F1810(void *self, void *a1, int count, void *arg) {
    if (count > 0) {
        H h;
        func_001F0C00(&h, a1);
        T t;
        func_001B6F08(&t, arg);
        Target *o = h.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x2A8);
        e->fn((char *)o + e->delta, (char *)t.get() + 0x10);
        func_001B6EB0(&t, 2);
        func_001F0BA8(&h, 2);
    }
}
