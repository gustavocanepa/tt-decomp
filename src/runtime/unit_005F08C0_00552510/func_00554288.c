#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554288_arg0 {
    char pad0[0xD88];
    s32 unkD88;
};

s32 func_00554288(struct func_00554288_arg0 *arg0) {
    return arg0->unkD88;
}
