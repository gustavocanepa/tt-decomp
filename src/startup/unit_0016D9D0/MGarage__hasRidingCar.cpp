#include "types.h"

extern "C" void func_0014D580(void *);
extern "C" void func_0014D528(void *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void MGarage__hasRidingCar(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 flag;
    s32 t;
    func_0014D580(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
    func_0014D528(buf0, 0x2);
    t = ~*(s32 *)((char *)((0x10000 + v_s0)) - 0x7DF0);
    flag = 0;
    if (t < 0) {
        flag = 1;
    }
    func_0029EA18(buf0, flag);
    if ((char *)arg0 != (char *)buf0) {
        v_s0 = buf0[0];
        if (v_s0 != 0) {
            func_002C0FE8(v_s0);
        }
        if (*(s32 *)(char *)arg0 != 0) {
            func_002C1050(*(s32 *)(char *)arg0);
        }
        *(s32 *)(char *)arg0 = v_s0;
    }
    func_0029CEF0(buf0, 0x2);
}
