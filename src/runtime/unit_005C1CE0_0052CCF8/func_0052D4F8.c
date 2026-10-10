#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052D4F8_arg0 {
    char pad0[0xD8];
    s32 unkD8;
};

void func_0052D4F8(struct func_0052D4F8_arg0 *arg0, s32 arg1) {
    arg0->unkD8 = arg1;
}
