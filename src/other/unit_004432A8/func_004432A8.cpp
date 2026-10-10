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
struct Stack { s32 f0; s32 f4; Val *top; };

extern "C" f32 func_0043E0B0(const Val *);
extern "C" void func_00447D00(Stack *, s32);
extern "C" void func_0043D780(Val *, s32);
extern "C" s32 func_00443E00(void *, s32);

extern "C" Val func_004432A8(void *self, s32 argc, Stack *st) {
    s32 n = 0;
    if (argc)
        n = (s32)func_0043E0B0(st->top - 1);
    func_00447D00(st, argc);
    Val t;
    func_0043D780(&t, self ? func_00443E00(self, n) : 0);
    return t;
}
