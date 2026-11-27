#include "types.h"

struct Target {
    char pad0[0x50];
    f32 value;
};

struct Handle {
    Target *obj;
    char pad4[0xC];
};

struct Val {
    s32 v;
    char pad4[0xC];
};

extern "C" void func_00139C38(Handle *h);
extern "C" void func_00139BE0(Handle *h, s32 flags);
extern "C" void func_00299B08(Val *v, s32 src);
extern "C" f32 func_0029B188(s32 v);
extern "C" void func_00299AB0(Val *v, s32 flags);

extern "C" void MCarModel__set_alpha(s32 a0, s32 a1, s32 a2, s32 argv) {
    Handle h;
    func_00139C38(&h);
    Target *t = h.obj;
    {
        Val v;
        Val *pv = &v;
        func_00299B08(pv, argv);
        t->value = func_0029B188(pv->v);
        func_00299AB0(pv, 2);
    }
    func_00139BE0(&h, 2);
}
