#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566A80_arg0 {
    char pad0[0x198];
    s64 unk198;
};

s64 func_00566A80(struct func_00566A80_arg0 *arg0) {
    return arg0->unk198;
}
