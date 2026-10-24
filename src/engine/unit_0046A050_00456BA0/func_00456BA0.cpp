#include "types.h"

extern char D_005DA1A8[];

extern "C" void *func_0045BDE0(void *p);
extern "C" void *func_0045A0B0(void *p);

struct C {
    s32 x0;
    s32 x4;
    s32 x8;
    char a[0x850];
    char b[0x8C];
    void *vtbl;
    C() __asm__("func_00456BA0");
};

C::C() {
    vtbl = D_005DA1A8;
    func_0045BDE0(a);
    func_0045A0B0(b);
    x0 = 0;
    x4 = 0;
    x8 = 0;
}
