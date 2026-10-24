#include "types.h"

struct Code {
    char c[5];
};

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *self, int value);
};

struct Obj {
    VEntry *vtbl;
    Code code;
};

extern "C" int func_00400D08(Code *code, int len);

extern "C" int func_003FF948(Obj *self, Code *out) {
    *out = self->code;
    int v = func_00400D08(out, 5);
    VEntry *e = &self->vtbl[4];
    return e->fn((char *)self + e->delta, v);
}
