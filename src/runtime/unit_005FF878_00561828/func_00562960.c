#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562960_arg0 {
    char pad0[0x110C];
    s32 unk110C;
};

s32 func_00562960(struct func_00562960_arg0 *arg0) {
    return arg0->unk110C;
}
