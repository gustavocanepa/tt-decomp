#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00566028_arg0 {
    char pad0[0xC];
    s32 *unkC;
};

s32 func_00566028(struct func_00566028_arg0 *arg0) {
    return *arg0->unkC;
}
