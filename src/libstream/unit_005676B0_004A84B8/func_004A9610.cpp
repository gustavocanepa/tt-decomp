#include "types.h"

/* The base class; its constructor is func_004A9768. Its vptr sits at 0x4. */
struct func_004A9768 {
    s32 m0;
    func_004A9768(s32, s32);
    virtual ~func_004A9768();
};

/* Named after its vtable so the compiler-made vptr store _vt$10D_00689E00 resolves. */
struct D_005DAD80 : func_004A9768 {
    s32 m8;
    s32 mC;
    D_005DAD80(s32 x, s32 a, s32 b);
    virtual ~D_005DAD80();
};

D_005DAD80::D_005DAD80(s32 x, s32 a, s32 b) : func_004A9768(a, b) {
    mC = x;
}
