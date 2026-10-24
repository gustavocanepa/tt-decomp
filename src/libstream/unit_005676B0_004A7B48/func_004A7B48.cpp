#include "types.h"

/* The base class; its constructor is func_004B3248. Its vptr sits at 0x4. */
struct func_004B3248 {
    s32 m0;
    char pad4[0x18];
    func_004B3248(s32, s32);
    virtual ~func_004B3248();
};

/* Named after its vtable so the compiler-made vptr store _vt$10D_00689E00 resolves. */
struct D_005DACF0 : func_004B3248 {
    s32 m20;
    s32 m24;
    s32 m28;
    s32 mC;
    D_005DACF0(s32 x, s32 a, s32 b);
    virtual ~D_005DACF0();
};

D_005DACF0::D_005DACF0(s32 x, s32 a, s32 b) : func_004B3248(a, b) {
    mC = x;
}
