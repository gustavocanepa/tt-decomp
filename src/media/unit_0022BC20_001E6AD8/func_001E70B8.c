#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E70B8_arg0 {
    char pad0[0xE4];
    f32 unkE4;
};

void func_001E70B8(struct func_001E70B8_arg0 *arg0, f32 fparg0) {
    arg0->unkE4 = fparg0;
}
