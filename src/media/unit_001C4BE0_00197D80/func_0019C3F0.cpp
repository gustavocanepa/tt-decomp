#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, const char *);
};

struct Target {
    char *vtbl;
};

struct Obj {
    char pad[0x24];
    char name[1];
};

extern "C" char *func_004F7B74(char *, const char *);

extern "C" bool func_0019C3F0(Obj *o, Target *t) {
    char path[0x30];
    path[0] = '/';
    func_004F7B74(path + 1, o->name);
    VEntry *e = (VEntry *)(t->vtbl + 0x60);
    return e->fn((char *)t + e->delta, path) == 0;
}
