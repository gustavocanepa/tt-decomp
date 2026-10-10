#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562600_arg0 {
    char pad0[0x74];
    s32 unk74;
};

s32 func_00562600(struct func_00562600_arg0 *arg0) {
    return arg0->unk74;
}
