#include "types.h"

struct Obj;
struct Struct_0020C290;

extern "C" void func_0021C2E0(void *arg0, int arg1);
extern "C" void func_0021C338(void *arg0, void *arg1);
extern "C" void func_0021CA78(struct Struct_0020C290 *arg0, f32 fparg0);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_00299B08(void *arg0, void *arg1);
extern "C" float func_0029B188(struct Obj *arg0);

extern "C" void func_0021C6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0 = arg3;

    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0021C338(buf0, (void *)arg1);
        s32 *p1 = buf1;
        func_00299B08(p1, (void *)s0);
        s32 base0 = buf0[0];
        f32 result = func_0029B188((struct Obj *)p1[0]);
        func_0021CA78((struct Struct_0020C290 *)base0, result);
        func_00299AB0(p1, 2);
        func_0021C2E0(buf0, 2);
    }
}
