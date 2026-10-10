#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041D200_arg0 {
    char pad0[0x5F0];
    s32 unk5F0;
};

void func_0041D200(struct func_0041D200_arg0 *arg0, s32 arg1) {
    arg0->unk5F0 = arg1;
}
