#include "types.h"

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

extern "C" void func_00202788(void *arg0, int arg1);
extern "C" void func_002027E0(void *arg0, void *arg1);
extern "C" void func_00218280(void *arg0, int arg1);
extern "C" void func_002182D8(void *arg0, void *arg1);
extern "C" void func_002187C0(Obj *arg0, void *arg1);

extern "C" void func_00218460(void *arg0, void *arg1, s32 n, void *arg3) {
    if (n > 0) {
        OHandle h0;
        Handle b;
        Handle *pb;
        func_002182D8(&h0, arg1);
        pb = &b;
        func_002027E0(pb, arg3);
        {
            Obj *o = h0.p;
            VEntry *e = (VEntry *)(o->vtbl + 0x268);
            e->fn((char *)o + e->delta);
        }
        func_002187C0(h0.p, pb->p);
        func_00202788(pb, 2);
        func_00218280(&h0, 2);
    }
}
