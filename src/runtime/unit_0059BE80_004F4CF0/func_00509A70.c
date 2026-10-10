#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00509A70_arg0 {
    char pad0[0x6];
    s16 unk6;
};

s16 func_00509A70(struct func_00509A70_arg0 *arg0) {
    return arg0->unk6;
}
