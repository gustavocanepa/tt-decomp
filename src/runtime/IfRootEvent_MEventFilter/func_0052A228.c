#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052A228_arg0 {
    char pad0[0x6E4];
    s32 unk6E4;
};

void func_0052A228(struct func_0052A228_arg0 *arg0, s32 arg1) {
    arg0->unk6E4 = arg1;
}
