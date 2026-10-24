#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x64];
    char *vtbl;
};

extern s32 D_0057973C;
extern Obj *D_00579740;

extern "C" void func_00108168(void);

extern "C" void func_00108578(void) {
    if (D_0057973C != 0) {
        D_0057973C = 0;
        Obj *o = D_00579740;
        VEntry *e = (VEntry *)(o->vtbl + 0x20);
        e->fn((char *)o + e->delta);
        func_00108168();
    }
}
