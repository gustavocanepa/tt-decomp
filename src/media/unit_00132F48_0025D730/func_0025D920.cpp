#include "types.h"

extern "C" void func_0025D418(void *arg0, s32 arg1);
extern "C" void func_0025D470(void *arg0);
extern "C" f32 func_0025DC88(s32 arg0);
extern "C" void func_00299AB0(s32 *arg0, s32 arg1);
extern "C" void func_0029B380(s32 *arg0, f32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_0025D920(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_0025D470(sp);
    {
        f32 t = func_0025DC88(sp[0]);
        p1 = sp10;
        func_0029B380(p1, t);
    }
    if (arg0 != p1) {
        temp_s0 = *p1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            func_002C1050(temp_a0);
        }
        *arg0 = temp_s0;
    }
    func_00299AB0(p1, 2);
    func_0025D418(sp, 2);
}
