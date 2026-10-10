#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051B0C0_arg0_unk10 {
    char pad0[0x10CC];
    s32 unk10CC;
};
struct func_0051B0C0_arg0 {
    char pad0[0x10];
    struct func_0051B0C0_arg0_unk10 *unk10;
};

void func_0051B0C0(struct func_0051B0C0_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk10CC = arg1;
}
