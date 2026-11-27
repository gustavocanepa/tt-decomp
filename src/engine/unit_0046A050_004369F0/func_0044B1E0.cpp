/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_0043D3B8(this, &o); }
    ~Val() { func_0043D510(this); }
};
struct Obj;
struct Scope;

extern "C" void func_0043D658(Val *) throw();
extern "C" Val func_0043E4E0(Val *v, Scope *s, s32 n, s32 t0, Obj *o);
extern "C" Val *func_00447FB0(Scope *s, s32 key);

extern "C" Val func_0044B1E0(Scope *s, s32 key, s32 n, s32 t0, Obj *o)
{
    Val *v = func_00447FB0(s, key);
    if (v != 0)
        return func_0043E4E0(v, s, n, t0, o);
    Val t;
    func_0043D658(&t);
    return t;
}
