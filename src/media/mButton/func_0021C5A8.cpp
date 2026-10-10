typedef int s32;

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct OHandle {
    Obj *p;
    char pad[0xC];
};

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_001B7F40(void *arg0, int arg1);
extern "C" void func_001B7F98(void *arg0, void *arg1);
extern "C" void func_0021C2E0(void *arg0, int arg1);
extern "C" void func_0021C338(void *arg0, void *arg1);
extern "C" void func_0021C908(Obj *arg0, void *arg1);

extern "C" void func_0021C5A8(void *arg0, void *arg1, s32 n, void *arg3) {
    if (n > 0) {
        OHandle h0;
        Handle b;
        Handle *pb;
        func_0021C338(&h0, arg1);
        pb = &b;
        func_001B7F98(pb, arg3);
        {
            Obj *o = h0.p;
            VEntry *e = (VEntry *)(o->vtbl + 0x268);
            e->fn((char *)o + e->delta);
        }
        func_0021C908(h0.p, pb->p);
        func_001B7F40(pb, 2);
        func_0021C2E0(&h0, 2);
    }
}
