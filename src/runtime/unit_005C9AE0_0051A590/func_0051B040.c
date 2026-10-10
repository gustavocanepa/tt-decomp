#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051B040_arg0_unk10 {
    char pad0[0x10BC];
    s32 unk10BC;
};
struct func_0051B040_arg0 {
    char pad0[0x10];
    struct func_0051B040_arg0_unk10 *unk10;
};

void func_0051B040(struct func_0051B040_arg0 *arg0, s32 arg1) {
    arg0->unk10->unk10BC = arg1;
}
