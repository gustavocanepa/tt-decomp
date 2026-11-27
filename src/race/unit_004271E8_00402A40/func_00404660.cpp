#include "types.h"

/* The base class, named after its constructor so that __13func_0043C310 resolves. */
struct func_00404F20 {
    char pad0[0xC];
    func_00404F20(const char *name, const char *type, const char *extra);
    virtual ~func_00404F20();
    void func_00404728(s32 n);
};

extern char D_005858D0[];
extern char D_00585920[];

/* No known name: named after its vtable (0x00688050) so that _vt$10D_00688050 resolves. */
struct D_005D96B0 : func_00404F20 {
    char pad10[0x16];
    char m26;
    char m27;
    char m28;
    D_005D96B0();
    virtual ~D_005D96B0();
};

D_005D96B0::D_005D96B0() : func_00404F20(0, D_005858D0, D_00585920) {
    func_00404728(0);
    m26 = 1;
    m27 = 1;
    m28 = 1;
}
