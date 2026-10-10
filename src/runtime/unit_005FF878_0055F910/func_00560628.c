#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560628_arg0 {
    char pad0[0x900];
    s32 unk900;
};

s32 func_00560628(struct func_00560628_arg0 *arg0) {
    return arg0->unk900;
}
