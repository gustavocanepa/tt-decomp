#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003703F0_arg0 {
    char pad0[0x118];
    s64 unk118;
};

s64 func_003703F0(struct func_003703F0_arg0 *arg0) {
    return arg0->unk118;
}
