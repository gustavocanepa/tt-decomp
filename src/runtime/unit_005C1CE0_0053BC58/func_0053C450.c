#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C450_arg0 {
    char pad0[0x1AC];
    s32 unk1AC;
};

void func_0053C450(struct func_0053C450_arg0 *arg0, s32 arg1) {
    arg0->unk1AC = arg1;
}
