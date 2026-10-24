/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Args { float f; s32 a; s32 b; };
struct Obj {
    char pad0[0x10];
    s32 u10;
    s32 u14;
    Args args;
};
extern "C" void func_00266440(void *);
extern "C" s32 func_0042BB68(s32, s32, Args *);
extern "C" void func_00266380(struct Obj *self, s32 a1, s32 a2, s32 a3, float dt) {
    if (self->u10) {
        func_00266440(self);
        Args p = self->args;
        p.f = dt;
        p.b = a2;
        p.a = a3;
        self->u14 = func_0042BB68(self->u10, a1, &p);
    }
}
