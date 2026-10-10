#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0047EE88_arg0 {
    char pad0[0x30];
    s32 (*unk30)(s32, void *);
    s32 unk34;
};

void func_0047EE88(struct func_0047EE88_arg0 *arg0) {
    s32 (*temp_v0)(s32, void *);

    temp_v0 = arg0->unk30;
    arg0->unk30 = NULL;
    if (temp_v0 != NULL) {
        temp_v0(arg0->unk34, arg0);
    }
}
