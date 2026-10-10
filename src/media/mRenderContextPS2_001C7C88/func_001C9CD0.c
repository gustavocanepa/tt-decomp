#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001C9CD0_arg0 {
    char pad0[0x1DA0];
    s32 unk1DA0;
};

void func_001C9CD0(struct func_001C9CD0_arg0 *arg0) {
    arg0->unk1DA0 = 1;
}
