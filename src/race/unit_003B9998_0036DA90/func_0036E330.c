#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0036E330_arg0 {
    char pad0[0x39DFC];
    s32 unk39DFC;
};

void func_0036E330(struct func_0036E330_arg0 *arg0, s32 arg1) {
    arg0->unk39DFC = arg1;
}
