#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00509A78_arg0 {
    char pad0[0x4];
    s16 unk4;
};

s16 func_00509A78(struct func_00509A78_arg0 *arg0) {
    return arg0->unk4;
}
