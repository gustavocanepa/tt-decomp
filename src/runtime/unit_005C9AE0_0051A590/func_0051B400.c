#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051B400_arg0_unk10 {
    char pad0[0x1118];
    s32 unk1118;
};
struct func_0051B400_arg0 {
    char pad0[0x10];
    struct func_0051B400_arg0_unk10 *unk10;
};

void func_0051B400(struct func_0051B400_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1118 = arg1;
}
