#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051BBE0_arg0_unk10 {
    char pad0[0x1170];
    s32 unk1170;
};
struct func_0051BBE0_arg0 {
    char pad0[0x10];
    struct func_0051BBE0_arg0_unk10 *unk10;
};

s32 func_0051BBE0(struct func_0051BBE0_arg0 *arg0) {
    return arg0->unk10->unk1170;
}
