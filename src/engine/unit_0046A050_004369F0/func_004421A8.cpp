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
    bool isObject() const { return type == 10; }
};
struct Stack { s32 f0; s32 f4; Val *top; };
struct Obj { char pad[0x58]; void *f58; };

extern "C" f32 func_0043E0B0(const Val *);
extern "C" void func_00447D00(Stack *, s32);
extern "C" void func_004478B8(void *, Obj *, s32);
extern "C" void func_004A6448(const char *, ...);
extern char D_00601800[];

extern "C" Val func_004421A8(Obj *self, s32 argc, Stack *st) {
    if (argc) {
        Val a(st->top[-1]);
        func_00447D00(st, argc);
        if (a.isObject()) {
            if (self->f58)
                func_004478B8(self->f58, self, a.v);
        } else {
            func_0043E0B0(&a);
            func_004A6448(D_00601800);
        }
    }
    return Val();
}
