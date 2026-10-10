#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051BB00_arg0_unk10 {
    char pad0[0x1158];
    s32 unk1158;
};
struct func_0051BB00_arg0 {
    char pad0[0x10];
    struct func_0051BB00_arg0_unk10 *unk10;
};

void func_0051BB00(struct func_0051BB00_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk1158 = arg1;
}
