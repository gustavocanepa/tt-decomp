#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551300_arg0 {
    char pad0[0xD010];
    s32 unkD010;
};

void func_00551300(struct func_00551300_arg0 *arg0, s32 arg1) {
    arg0->unkD010 = arg1;
}
