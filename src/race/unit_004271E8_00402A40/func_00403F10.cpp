#include "types.h"

/* The base class, named after its constructor so that __13func_0043C310 resolves. */
struct func_00404F20 {
    char pad0[8];
    s32 m8;
    func_00404F20(const char *name, const char *type, s32 n);
    virtual ~func_00404F20();
    void func_00403FD0(s32 n);
};

extern char D_00585868[];

/* No known name: named after its vtable (0x00688130) so that _vt$10D_00688130 resolves. */
struct D_005D95D0 : func_00404F20 {
    char pad10[0xA];
    char m1A;
    D_005D95D0();
    virtual ~D_005D95D0();
};

D_005D95D0::D_005D95D0() : func_00404F20(0, D_00585868, m8) {
    func_00403FD0(0);
    m1A = 1;
}
