#include "types.h"

struct Entry {
    s32 f0;
    s32 f4;
};

struct Item {
    char *name;
    s32 f4;
};

struct A {
    char pad0[0x24];
    u16 count;
    char pad1[0x26];
    Item *items;
};

struct B {
    char pad0[0x10];
    char *out;
};

extern "C" s32 func_0041FBA8(s32 arg0);
extern "C" Entry *func_00567060(const char *name, Entry *table, int count);

extern "C" void func_0041FBE0(A *arg0, B *arg1, s32 arg2, s32 arg3)
{
    s32 s3 = arg2;
    s32 s2 = arg3;

    if (s3 != 0) {
        if (s2 == 0) {
            s2 = func_0041FBA8(s3);
        }
        u32 s0 = 0;
        if (arg0->count != 0) {
            do {
                Entry *r = func_00567060(arg0->items[s0].name, (Entry *)s3, s2);
                s32 a0 = s0 << 2;
                s0 += 1;
                if (r != 0) {
                    s32 v = r->f4;
                    *(s32 *)(a0 + (s32)arg1->out) = v;
                }
            } while (s0 < (u32)arg0->count);
        }
    }
}
