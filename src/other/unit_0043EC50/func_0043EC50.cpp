typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val {
    s32 type;
    s32 v;
    bool isString() const { return (u32)(type - 3) < 2; }
};
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);
extern "C" const char *func_004772A8(Val *);
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" f32 func_0043E0B0(const Val *);
extern "C" void func_0043F408(Val *, s32 type);

extern "C" s32 func_0043EC50(const Val *a, const Val *b) {
    if (a->isString() || b->isString()) {
        Val ta, tb;
        s32 r;
        func_0043D3B8(&ta, a);
        func_0043D3B8(&tb, b);
        func_0043F408(&ta, 10);
        func_0043F408(&tb, 10);
        r = func_0043E0B0(&ta) > func_0043E0B0(&tb);
        func_0043D510(&tb);
        func_0043D510(&ta);
        return r;
    }
    return func_0043E0B0(a) > func_0043E0B0(b);
}
