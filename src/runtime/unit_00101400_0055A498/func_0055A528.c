#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055A528_arg0 {
    char pad0[0x128];
    s32 unk128;
};

void func_0055A528(struct func_0055A528_arg0 *arg0, s32 arg1) {
    arg0->unk128 = arg1;
}
