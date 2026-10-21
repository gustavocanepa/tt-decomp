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
extern "C" void func_00447D00(void *, s32);

extern "C" Val func_00443360(void *self, s32 n, void *list) {
    func_00447D00(list, n);
    Val t;
    func_0043D780(&t, 0);
    return t;
}
