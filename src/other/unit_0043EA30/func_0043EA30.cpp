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
extern "C" const char *func_0043DEF8(Val *);
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" f32 func_0043E0B0(const Val *);
extern "C" void func_0043D7C8(Val *, f32);
extern "C" u32 func_004A8368(const char *);
extern "C" s32 func_0043D280(u32 len);
extern "C" char *func_004F7B74(char *dst, const char *src);

extern "C" void func_0043EA30(Val *a, const Val *b) {
    if (a->isString() || b->isString()) {
        Val ta, tb;
        s32 type = 3;
        const char *sa, *sb;
        u32 la, lb;
        func_0043D3B8(&ta, a);
        func_0043D3B8(&tb, b);
        sa = func_0043DEF8(&ta);
        sb = func_0043DEF8(&tb);
        la = func_004A8368(sa);
        lb = func_004A8368(sb);
        func_0043D510(a);
        a->type = type;
        a->v = func_0043D280(la + lb);
        func_004F7B74((char *)a->v + 2, sa);
        func_004F7B74((char *)a->v + la + 2, sb);
        func_0043D510(&tb);
        func_0043D510(&ta);
        return;
    }
    func_0043D7C8(a, func_0043E0B0(a) + func_0043E0B0(b));
}
