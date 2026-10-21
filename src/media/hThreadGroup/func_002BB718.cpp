#include "types.h"

extern "C" void func_002BB508(void *arg0, s32 arg1);
extern "C" void func_002BB560(void *arg0);
extern "C" void func_002BBBD0(s32 *arg0, s32 arg1);
extern "C" void func_002A75A8(s32 *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_002BB718(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_002BB560(sp);
    p1 = sp10;
    func_002BBBD0(p1, sp[0]);
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
    func_002A75A8(p1, 2);
    func_002BB508(sp, 2);
}
