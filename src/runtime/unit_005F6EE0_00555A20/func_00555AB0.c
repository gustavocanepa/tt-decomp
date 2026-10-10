#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00555AB0_arg0_unk4 {
    char pad0[0xCC];
    s32 unkCC;
};
struct func_00555AB0_arg0 {
    char pad0[0x4];
    struct func_00555AB0_arg0_unk4 *unk4;
};

s32 func_00555AB0(struct func_00555AB0_arg0 *arg0) {
    return arg0->unk4->unkCC;
}
