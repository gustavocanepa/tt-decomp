#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554508_arg0 {
    char pad0[0xDA4];
    s32 unkDA4;
};

s32 func_00554508(struct func_00554508_arg0 *arg0) {
    return arg0->unkDA4;
}
