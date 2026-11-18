#include "types.h"

extern "C" void func_00159750(void *, void *);
extern "C" void func_001596F8(void *, s32);
extern "C" void func_0051A7C8(void *, void *, void *, s32, s32);

typedef s32 (*CountCallback_0017DD78)(void *);

extern "C" void func_0015A200(s32 arg0, void *arg1, s32 arg2, void **arg3) {
    u32 descriptor[5];
    func_00159750(descriptor, arg1);

    void *object = *arg3;
    u8 *node = *(u8 **)descriptor;
    void *begin = *(void **)(node + 0x10);
    u8 *method_entry = *(u8 **)((u8 *)object + 4) + 0x68;
    s16 offset = *(s16 *)method_entry;
    CountCallback_0017DD78 count = *(CountCallback_0017DD78 *)(method_entry + 4);
    s32 first = count((u8 *)object + offset);

    descriptor[4] = (u32)begin;
    void *first_end = (u8 *)begin + first * 8;
    u32 capacity = *(u32 *)((u8 *)begin + 0xC80);
    void *last_end = (u8 *)begin + capacity * 8;
    func_0051A7C8(begin, first_end, last_end, 0, 0);
    func_001596F8(descriptor, 2);
}
