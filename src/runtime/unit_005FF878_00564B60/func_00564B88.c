#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564B88_arg0 {
    char pad0[0x40];
    s64 unk40;
};

s64 func_00564B88(struct func_00564B88_arg0 *arg0) {
    return arg0->unk40;
}
