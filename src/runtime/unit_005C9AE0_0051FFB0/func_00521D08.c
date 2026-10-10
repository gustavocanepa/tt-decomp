#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00521D08_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

s32 func_00521D08(struct func_00521D08_arg0 *arg0) {
    return arg0->unkA8;
}
