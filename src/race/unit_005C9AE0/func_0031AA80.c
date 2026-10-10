#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031AA80_arg0 {
    char pad0[0xA48];
    s32 unkA48;
};

void func_0031AA80(struct func_0031AA80_arg0 *arg0, s32 arg1) {
    arg0->unkA48 = arg1;
}
