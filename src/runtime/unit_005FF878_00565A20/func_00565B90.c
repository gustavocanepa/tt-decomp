#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565B90_arg0 {
    char pad0[0xA0];
    s64 unkA0;
};

s64 func_00565B90(struct func_00565B90_arg0 *arg0) {
    return arg0->unkA0;
}
