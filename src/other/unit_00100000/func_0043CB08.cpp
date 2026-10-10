typedef int s32;
typedef unsigned int u32;

struct Val { s32 type; s32 v; };
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3E0(Val *, const Val *);
extern "C" u32 func_004A8368(const char *s);
struct String2;
extern "C" String2 *func_00550E18(String2 *str, u32 pos, u32 n1, const char *s, u32 n2);
struct String2 {
    char *dat;
    String2 &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_00550E18(this, pos, n1, s, n2); }
    String2 &assign(const char *s, u32 n) { return replace(0, (u32)-1, s, n); }
    String2 &assign(const char *s) { return assign(s, func_004A8368(s)); }
};
struct Obj {
    char pad[0x16C];
    s32 f16C;
    s32 f170;
    Val val;
    String2 str;
};
extern "C" void func_0043CB08(Obj *self, Val *v, const char *s) {
    self->f16C = 1;
    self->f170 = -1;
    func_0043D3E0(&self->val, v);
    self->str.assign(s);
    func_0043D510(v);
}
