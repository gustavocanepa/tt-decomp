#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00321EF8_arg0 {
    char pad0[0xE8];
    s32 unkE8;
};

s32 func_00321EF8(struct func_00321EF8_arg0 *arg0) {
    return arg0->unkE8;
}
