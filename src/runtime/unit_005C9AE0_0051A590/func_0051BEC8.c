#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051BEC8_arg0_unk10 {
    char pad0[0x1440];
    s32 unk1440;
};
struct func_0051BEC8_arg0 {
    char pad0[0x10];
    struct func_0051BEC8_arg0_unk10 *unk10;
};

s32 func_0051BEC8(struct func_0051BEC8_arg0 *arg0) {
    return arg0->unk10->unk1440;
}
