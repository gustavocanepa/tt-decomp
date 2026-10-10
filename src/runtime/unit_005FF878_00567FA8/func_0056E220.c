#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056E220_arg0 {
    char pad0[0x90];
    s32 unk90;
};

void func_0056E220(struct func_0056E220_arg0 *arg0, s32 arg1) {
    arg0->unk90 = arg1;
}
