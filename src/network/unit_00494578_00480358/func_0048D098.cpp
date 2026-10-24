#include "types.h"

typedef void (*FnPtr)(s32 arg0);

struct Obj {
    char pad0[0xC];
    FnPtr unkC;
};

extern "C" void func_0048D098(struct Obj *arg0, s32 arg1) {
    arg0->unkC(arg1);
}
