#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552BF8_arg0 {
    char pad0[0xBC];
    s32 unkBC;
};

s32 func_00552BF8(struct func_00552BF8_arg0 *arg0) {
    return arg0->unkBC;
}
