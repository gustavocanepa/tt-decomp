#include "types.h"
extern "C" float D_00585F14;
extern "C" s32 D_00585F10;
extern "C" s32 D_00585F18;
extern "C" s32 D_00585F1C;
extern "C" float D_00585F20;
extern "C" void func_0042B3F8(int a, int b, float d, int c);
extern "C" void func_0042CAF8(void *s, int a, float f, int b);
extern "C" int func_0042CEF0(int n);
extern "C" void func_0042CFF8(void);
extern "C" void func_0042CF18(s32 arg0, s32 arg1, s32 arg2, float fparg0) {
    float t;
    s32 v;
    t = fparg0 * D_00585F14;
    func_0042CFF8();
    v = func_0042CEF0(arg0);
    switch (v) {
    case 0:
        D_00585F10 = 2;
        func_0042CAF8((void *)arg0, arg1, t, arg2);
        break;
    case 1:
        D_00585F10 = v;
        func_0042B3F8(arg0 - 10, arg1, t, arg2);
        break;
    }
    D_00585F18 = arg0;
    D_00585F1C = arg1;
    D_00585F20 = fparg0;
}
