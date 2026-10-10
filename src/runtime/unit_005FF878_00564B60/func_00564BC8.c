#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564BC8_arg0 {
    char pad0[0x70];
    s64 unk70;
};

s64 func_00564BC8(struct func_00564BC8_arg0 *arg0) {
    return arg0->unk70;
}
