#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536C28_arg0 {
    char pad0[0xCC];
    s32 unkCC;
};

s32 func_00536C28(struct func_00536C28_arg0 *arg0) {
    return arg0->unkCC;
}
