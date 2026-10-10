/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Val;
extern "C" void func_0043D510(Val *);
extern "C" Val *func_0043D3B8(Val *, const Val *);

/* the script value: type 1 is nil; func_0043D510 releases the payload and sets nil */
struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_0043D3B8(this, &o); }
    ~Val() { func_0043D510(this); }
};
extern "C" void func_0043DE58(Val *, void *);
extern "C" void *func_0056BB78(void *);

struct Obj { char pad[0x58]; void *f58; };

extern "C" Val func_00441C30(Obj *o) {
    Val t;
    func_0043DE58(&t, o->f58 ? func_0056BB78(o->f58) : o);
    return t;
}
