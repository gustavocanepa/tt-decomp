#include "types.h"

/* The base class, named after its constructor (func_003F1C00) so that __13func_0042A5B8iii
   resolves. The vptr sits after its 4 bytes of data. */
struct func_003F1C00 {
    s32 m0;
    func_003F1C00(s32, s32, s32);
    virtual ~func_003F1C00();
};

/* No known name: named after its vtable (0x006867B0) so that _vt$10D_006867B0 resolves. */
struct D_005D7800 : func_003F1C00 {
    char pad[0x20];
    s32 m28;
    s32 m2C;
    D_005D7800(s32 arg);
    virtual ~D_005D7800();
};

D_005D7800::D_005D7800(s32 arg) : func_003F1C00(arg, 0, 0), m28(0), m2C(0) {
}
