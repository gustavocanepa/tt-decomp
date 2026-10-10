#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00448000(void *, s32);
struct func_00447FB0_arg0 {
    char pad0[0x10];
    void *unk10;
};

s32 func_00447FB0(struct func_00447FB0_arg0 *arg0, s32 arg1) {
    s32 r;
    void *n;
    for (;;) {
        r = func_00448000(arg0, arg1);
        if (r != 0) break;
        n = arg0->unk10;
        arg0 = n;
        if (n == NULL) break;
    }
    return r;
}
