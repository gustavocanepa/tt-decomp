#include "types.h"

struct Inner {
    char pad0[0x70];
    s32 id;
    char pad74[0x80 - 0x74];
    void *target;
};

struct Obj {
    char pad0[0x6C];
    Inner *inner;
};

extern char D_005F6DA0[]; /* "crs/bestline/%s" */
extern "C" const char *func_0040EE28(s32 id);
extern "C" int func_004A6500(char *buf, const char *fmt, ...);
extern "C" s32 func_0034ACF0(void *target, char *name);

extern "C" void func_00371608(Obj *self) {
    char buf[0x80];
    const char *name = func_0040EE28(self->inner->id);
    if (name) {
        func_004A6500(buf, D_005F6DA0, name);
        func_0034ACF0(self->inner->target, buf);
    }
}
