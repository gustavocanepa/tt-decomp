#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00576228_arg0 {
    char pad0[0x18];
    s16 unk18;
};

s16 func_00576228(struct func_00576228_arg0 *arg0) {
    return arg0->unk18;
}
