#include "types.h"

struct DoubleBuf {
    s32 buf[2];
    s32 arg;
    s32 cur;
};

extern DoubleBuf D_005794E0;
extern "C" void func_0046F4C0(s32, s32);
extern "C" void func_0046F680(void);

extern "C" void func_00106E90(void) {
    D_005794E0.cur = 1 - D_005794E0.cur;
    func_0046F4C0(D_005794E0.buf[D_005794E0.cur], D_005794E0.arg);
    func_0046F680();
}
