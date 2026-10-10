#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005382E0_arg0 {
    char pad0[0x50];
    s32 unk50;
};

s32 func_005382E0(struct func_005382E0_arg0 *arg0) {
    return arg0->unk50;
}
