#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00410900_arg0 {
    char pad0[0x18];
    u8 unk18;
};

s32 func_00410900(struct func_00410900_arg0 *arg0) {
    return arg0->unk18 != 0;
}
