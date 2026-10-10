#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00410920_arg0 {
    char pad0[0x19];
    u8 unk19;
};

s32 func_00410920(struct func_00410920_arg0 *arg0) {
    return arg0->unk19 != 0;
}
