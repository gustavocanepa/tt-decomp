#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *, int);
};

struct Obj {
    struct VEntry *vtbl;
};

extern "C" void func_002BCAE0(void *arg0, int arg1);

extern "C" void func_002BD510(struct Obj *arg0, int arg1, int arg2) {
    struct VEntry *e = (struct VEntry *)((char *)arg0->vtbl + 0x10);

    func_002BCAE0(e->fn((char *)arg0 + e->delta, arg1), arg2);
}
