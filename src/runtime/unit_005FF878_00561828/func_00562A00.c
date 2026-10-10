#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562A00_arg0 {
    char pad0[0x1134];
    s32 unk1134;
};

s32 func_00562A00(struct func_00562A00_arg0 *arg0) {
    return arg0->unk1134;
}
