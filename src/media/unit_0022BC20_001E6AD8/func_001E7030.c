#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E7030_arg0 {
    char pad0[0xF0];
    s32 unkF0;
};

void func_001E7030(struct func_001E7030_arg0 *arg0) {
    arg0->unkF0 = (s32) (arg0->unkF0 | 0x40);
}
