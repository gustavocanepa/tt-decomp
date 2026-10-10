#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E98_arg0 {
    char pad0[0x8];
    s64 unk8;
};

s64 func_00565E98(struct func_00565E98_arg0 *arg0) {
    return arg0->unk8;
}
