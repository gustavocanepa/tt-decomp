#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0037BF68_arg0_unk138 {
    char pad0[0x958];
    s32 unk958;
};
struct func_0037BF68_arg0 {
    char pad0[0x138];
    struct func_0037BF68_arg0_unk138 *unk138;
};

s32 func_0037BF68(struct func_0037BF68_arg0 *arg0) {
    return arg0->unk138->unk958;
}
