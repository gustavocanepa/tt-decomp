#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E4EC8_arg0 {
    char pad0[0x6D0];
    s32 unk6D0;
};

void func_001E4EC8(struct func_001E4EC8_arg0 *arg0, s32 arg1) {
    arg0->unk6D0 = arg1;
}
