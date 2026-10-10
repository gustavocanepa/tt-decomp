#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0037BF10_arg0_unk138 {
    char pad0[0xB0];
    s64 unkB0;
};
struct func_0037BF10_arg0 {
    char pad0[0x138];
    struct func_0037BF10_arg0_unk138 *unk138;
};

s64 func_0037BF10(struct func_0037BF10_arg0 *arg0) {
    return arg0->unk138->unkB0;
}
