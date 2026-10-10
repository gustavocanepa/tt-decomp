#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552D50_arg0 {
    char pad0[0xB8C];
    s32 unkB8C;
};

s32 func_00552D50(struct func_00552D50_arg0 *arg0) {
    return arg0->unkB8C;
}
