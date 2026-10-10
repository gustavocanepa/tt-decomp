#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00322008_arg0 {
    char pad0[0x150];
    s32 unk150;
};

s32 func_00322008(struct func_00322008_arg0 *arg0) {
    return arg0->unk150;
}
