#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C780_arg0 {
    char pad0[0x150];
    s32 unk150;
};

s32 func_0053C780(struct func_0053C780_arg0 *arg0) {
    return ((s32) arg0->unk150 >> 6) & 1;
}
