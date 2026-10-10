#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051BBD0_arg0_unk10 {
    char pad0[0x116C];
    s32 unk116C;
};
struct func_0051BBD0_arg0 {
    char pad0[0x10];
    struct func_0051BBD0_arg0_unk10 *unk10;
};

void func_0051BBD0(struct func_0051BBD0_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk116C = arg1;
}
