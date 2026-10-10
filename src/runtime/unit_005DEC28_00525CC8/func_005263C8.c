#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005263C8_arg0 {
    char pad0[0x5C];
    f32 unk5C;
};

void func_005263C8(struct func_005263C8_arg0 *arg0, f32 fparg0) {
    arg0->unk5C = fparg0;
}
