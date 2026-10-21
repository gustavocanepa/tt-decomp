#include "types.h"

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" const char *strobe__Any__toString(Val *);
extern "C" s32 func_004A8268(const char *, const char *);

extern "C" s32 func_0043ED48(const Val *a, const Val *b) {
    Val ta, tb;
    s32 r;
    func_0043D3B8(&ta, a);
    func_0043D3B8(&tb, b);
    r = func_004A8268(strobe__Any__toString(&ta), strobe__Any__toString(&tb)) > 0;
    func_0043D510(&tb);
    func_0043D510(&ta);
    return r;
}
