#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051AA68_arg0_unk10 {
    char pad0[0x1C];
    s32 unk1C;
};
struct func_0051AA68_arg0 {
    char pad0[0x10];
    struct func_0051AA68_arg0_unk10 *unk10;
};

void func_0051AA68(struct func_0051AA68_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1C = arg1;
}
