#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0033DF28_arg0 {
    char pad0[0xD8C];
    s32 unkD8C;
};

s32 func_0033DF28(struct func_0033DF28_arg0 *arg0) {
    return arg0->unkD8C == 4;
}
