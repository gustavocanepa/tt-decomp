#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536C30_arg0 {
    char pad0[0xCC];
    s32 unkCC;
};

void func_00536C30(struct func_00536C30_arg0 *arg0, s32 arg1) {
    arg0->unkCC = arg1;
}
