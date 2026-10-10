#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051AFA8_arg0_unk10 {
    char pad0[0x8C];
    s32 unk8C;
};
struct func_0051AFA8_arg0 {
    char pad0[0x10];
    struct func_0051AFA8_arg0_unk10 *unk10;
};

void func_0051AFA8(struct func_0051AFA8_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk8C = arg1;
}
