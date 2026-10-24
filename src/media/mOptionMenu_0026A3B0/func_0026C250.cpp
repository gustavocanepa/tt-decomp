#include "types.h"
struct S;
extern "C" void func_0026AB58(S *arg0, s32 arg1);
extern "C" s32 func_0026C100(S *arg0, s32 arg1);
extern "C" void func_004AC580(char *arg0, s32 arg1);

extern "C" void func_0026C250(S *arg0, s32 arg1, s32 arg2) {
    s32 r = func_0026C100(arg0, arg2);
    if (r >= 0) {
        func_004AC580((char *)arg0 + 0xF4, r);
    }
    if (arg1 != 0) {
        func_0026AB58(arg0, arg1);
    }
}
