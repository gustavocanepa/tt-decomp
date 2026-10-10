#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0051ADB8_arg0_unk10 {
    char pad0[0x70];
    s32 unk70;
};
struct func_0051ADB8_arg0 {
    char pad0[0x10];
    struct func_0051ADB8_arg0_unk10 *unk10;
};

s32 func_0051ADB8(struct func_0051ADB8_arg0 *arg0) {
    return arg0->unk10->unk70;
}
