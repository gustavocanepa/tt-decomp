#include "types.h"

struct func_0047ED98_blk {
    s32 (*fn)(s32, void *);
    s32 arg;
};

extern "C" void func_0047ED98(void *arg0) {
    func_0047ED98_blk *p = (func_0047ED98_blk *)((char *)arg0 + 0x6C);
    s32 (*temp_v0)(s32, void *);

    temp_v0 = p->fn;
    if (temp_v0 != 0) {
        temp_v0(p->arg, arg0);
    }
}
