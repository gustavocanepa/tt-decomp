#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559948_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_00559948(struct func_00559948_arg0 *arg0) {
    return arg0->unk10;
}
