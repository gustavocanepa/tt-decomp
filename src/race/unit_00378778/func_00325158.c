#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00325158_arg0 {
    char pad0[0x1AC];
    s32 unk1AC;
};

void func_00325158(struct func_00325158_arg0 *arg0, s32 arg1) {
    arg0->unk1AC = arg1;
}
