#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562A10_arg0 {
    char pad0[0x1138];
    s32 unk1138;
};

s32 func_00562A10(struct func_00562A10_arg0 *arg0) {
    return arg0->unk1138;
}
