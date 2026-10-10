#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003F8090_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

s32 func_003F8090(struct func_003F8090_arg0 *arg0) {
    return arg0->unkD4 & 1;
}
