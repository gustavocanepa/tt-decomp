#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[4];
    VEntry *vtbl;
};

extern "C" int func_00234490(void *arg0, void *arg1, struct Obj *obj) {
    VEntry *e = &obj->vtbl[69];

    e->fn((char *)obj + e->delta);
    return 1;
}
