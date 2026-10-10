#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562D88_arg0 {
    char pad0[0x1174];
    s32 unk1174;
};

s32 func_00562D88(struct func_00562D88_arg0 *arg0) {
    return arg0->unk1174;
}
