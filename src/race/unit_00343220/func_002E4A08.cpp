#include "types.h"

struct Obj {
    char pad0[0xC];
    f32 unkC;
};

extern "C" void func_002E4A08(struct Obj *arg0, f32 fparg0) {
    if (fparg0 > 0.8f) {
        arg0->unkC = 0.8f;
        return;
    }
    arg0->unkC = fparg0;
}
