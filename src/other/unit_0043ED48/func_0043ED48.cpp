typedef int s32;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" const char *func_0043DEF8(Val *);
extern "C" s32 func_004A8268(const char *, const char *);

extern "C" s32 func_0043ED48(const Val *a, const Val *b) {
    Val ta, tb;
    s32 r;
    func_0043D3B8(&ta, a);
    func_0043D3B8(&tb, b);
    r = func_004A8268(func_0043DEF8(&ta), func_0043DEF8(&tb)) > 0;
    func_0043D510(&tb);
    func_0043D510(&ta);
    return r;
}
