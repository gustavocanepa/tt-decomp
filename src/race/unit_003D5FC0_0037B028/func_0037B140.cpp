#include "types.h"

struct func_0037B140_arg0 {
    char pad0[0x160];
    s8 unk160;
    u8 unk161;
    char pad1[3];
    s8 unk165;
    u8 unk166;
};

struct func_0037B140_arg1 {
    char pad0[0xE8];
    s32 unk60;
};

extern "C" void func_0040CE20(void *a, void *b);
extern "C" void func_0037B078(void *a, void *b);

extern "C" void func_0037B140(struct func_0037B140_arg0 *arg0,
                              struct func_0037B140_arg1 *arg1,
                              void *arg2) {
    s32 one = 1;
    func_0040CE20(arg0, arg2);
    arg0->unk166 = (s8)one;
    s32 v = arg1->unk60;
    if (v >= 0) {
        arg0->unk160 = (s8)v;
        u8 b = *(u8 *)((char *)arg1 + 0xE8);
        arg0->unk165 = (s8)one;
        arg0->unk161 = b;
    }
    func_0037B078(arg0, arg1);
}
