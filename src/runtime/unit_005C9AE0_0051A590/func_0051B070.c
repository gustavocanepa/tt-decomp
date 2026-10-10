#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051B070_arg0_unk10 {
    char pad0[0x10C4];
    s32 unk10C4;
};
struct func_0051B070_arg0 {
    char pad0[0x10];
    struct func_0051B070_arg0_unk10 *unk10;
};

s32 func_0051B070(struct func_0051B070_arg0 *arg0) {
    return arg0->unk10->unk10C4;
}
