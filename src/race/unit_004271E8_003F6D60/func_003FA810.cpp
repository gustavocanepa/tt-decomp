#include "types.h"

struct Obj {
    int m0;
    void *items;
    int count;
};

extern "C" u64 func_0040FC00(void *x);
extern "C" void *func_004F4E58(const void *key, const void *base, int n, int size, int (*cmp)(const void *, const void *));
extern "C" int func_003FA7E8(const void *a, const void *b);
extern "C" void func_003FA6A0(Obj *o, void *x);

extern "C" void func_003FA810(Obj *o, void *x) {
    u64 key = func_0040FC00(x);
    if (func_004F4E58(&key, o->items, o->count, 0x238, func_003FA7E8) == 0)
        func_003FA6A0(o, x);
}
