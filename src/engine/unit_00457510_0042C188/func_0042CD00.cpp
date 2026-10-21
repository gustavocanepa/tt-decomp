#include "types.h"
extern "C" char D_0076A028[];
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0042CB70(void *s, float x, int a, float y, int b);
extern "C" int func_0042CC18(void *s, int a, float f, int b);
extern "C" void func_0042CD00(void *s, int a, int b, float x, float y) {
    int r;
    func_004A4D68(D_0076A028);
    r = func_0042CC18(s, a, y, b);
    if (r >= 0) {
        func_0042CB70((void *)r, x, a, y, b);
    }
    func_004A4DD8(D_0076A028);
}
