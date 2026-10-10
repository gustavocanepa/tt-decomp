#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00512108_arg0 {
    char pad0[0xE0];
    s32 unkE0;
};

s32 func_00512108(struct func_00512108_arg0 *arg0) {
    return arg0->unkE0;
}
