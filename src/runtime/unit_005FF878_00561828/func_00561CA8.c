#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00561CA8_arg0 {
    char pad0[0xB20];
    s32 unkB20;
};

s32 func_00561CA8(struct func_00561CA8_arg0 *arg0) {
    return arg0->unkB20;
}
