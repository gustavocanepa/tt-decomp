#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051BA68_arg0_unk10 {
    char pad0[0x117C];
    s32 unk117C;
};
struct func_0051BA68_arg0 {
    char pad0[0x10];
    struct func_0051BA68_arg0_unk10 *unk10;
};

void func_0051BA68(struct func_0051BA68_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk117C = arg1;
}
