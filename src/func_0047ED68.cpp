#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0047ED68_arg0 {
    char pad0[0x64];
    s32 (*unk64)(s32, void *);
    s32 unk68;
};

struct func_0047ED68_tail {
    s32 (*fn)(s32, void *);
    s32 arg;
};

void func_0047ED68(struct func_0047ED68_arg0 *arg0) {
    struct func_0047ED68_tail *t;
    s32 (*temp_v0)(s32, void *);

    t = (struct func_0047ED68_tail *)((char *)arg0 + 0x64);
    temp_v0 = t->fn;
    if (temp_v0 != NULL) {
        temp_v0(t->arg, arg0);
    }
}
