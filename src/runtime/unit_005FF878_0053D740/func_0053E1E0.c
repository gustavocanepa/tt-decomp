#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053E1E0_arg0 {
    char pad0[0x1A4];
    s32 unk1A4;
};

void func_0053E1E0(struct func_0053E1E0_arg0 *arg0, s32 arg1) {
    arg0->unk1A4 = arg1;
}
