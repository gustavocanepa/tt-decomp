#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0025DCA8_arg0 {
    char pad0[0x6C];
    f32 unk6C;
};

void func_0025DCA8(struct func_0025DCA8_arg0 *arg0, f32 fparg0) {
    arg0->unk6C = (f32) (0x1.0000000000000p+0f / fparg0);
}
