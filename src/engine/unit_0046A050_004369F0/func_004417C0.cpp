#include "types.h"

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
extern "C" void func_0043D780(Val *, s32);

struct Obj { char pad[0x74]; s32 f74; };

extern "C" Val func_004417C0(Obj *o) {
    Val t;
    func_0043D780(&t, o->f74);
    return t;
}
