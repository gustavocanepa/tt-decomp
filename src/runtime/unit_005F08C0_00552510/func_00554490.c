#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554490_arg0 {
    char pad0[0xE18];
    s32 unkE18;
};

s32 func_00554490(struct func_00554490_arg0 *arg0) {
    return arg0->unkE18;
}
