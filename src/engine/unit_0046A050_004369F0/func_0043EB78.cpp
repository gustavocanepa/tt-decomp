#include "types.h"

struct Val {
    s32 type;
    s32 v;
    bool isString() const { return (u32)(type - 3) < 2; }
};
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" const char *strobe__Any__toString(Val *);
extern "C" s32 func_004A8268(const char *, const char *);
extern "C" f32 func_0043E0B0(const Val *);

extern "C" s32 func_0043EB78(const Val *a, const Val *b) {
    if (a->isString() || b->isString()) {
        Val ta, tb;
        s32 r;
        func_0043D3B8(&ta, a);
        func_0043D3B8(&tb, b);
        r = func_004A8268(strobe__Any__toString(&ta), strobe__Any__toString(&tb)) < 0;
        func_0043D510(&tb);
        func_0043D510(&ta);
        return r;
    }
    return func_0043E0B0(a) < func_0043E0B0(b);
}
