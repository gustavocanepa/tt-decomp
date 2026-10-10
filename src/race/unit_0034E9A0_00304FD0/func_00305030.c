#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00305030_arg0 {
    char pad0[0x24114];
    s16 unk24114;
};

s16 func_00305030(struct func_00305030_arg0 *arg0) {
    return arg0->unk24114;
}
