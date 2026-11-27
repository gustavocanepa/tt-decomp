#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" s32 func_00445370(void *, void *);
extern "C" void func_00439EC8(s32, s32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_00478C98(s32);
extern "C" void func_0043A298(s32, void *);
extern "C" void func_00473178(s32);
extern "C" void func_0047525C(s32);

struct func_0043F780_arg0 {
    char pad0[0x6E14];
    s32 unk6E14;
    char pad6E18[0x20];
    s32 unk6E38;
};
struct func_0043F780_v_s0 {
    char pad0[0x4];
    s32 unk4;
};

extern "C" void func_0043F780(s32 *arg0, void *arg1, s32 arg2) {
    s32 buf0[4];
    s32 v_s0;
    if (((struct func_0043F780_arg0 *)arg0)->unk6E38 == 0) {
        buf0[0] = 0x80ffffff;
        func_00439EC8(((struct func_0043F780_arg0 *)arg0)->unk6E14, func_00445370((char *)arg0 + 0x6e18, buf0));
    }
    v_s0 = ((struct func_0043F780_arg0 *)arg0)->unk6E14;
    func_0046F0F8(0x2);
    func_00478C98(0x9);
    ((struct func_0043F780_v_s0 *)v_s0)->unk4 = 0x1;
    if (arg1 != 0) {
        func_0043A298(((struct func_0043F780_arg0 *)arg0)->unk6E14, arg1);
    }
    func_00473178(0x2);
    func_0047525C(arg2);
    func_00473178(0);
}
