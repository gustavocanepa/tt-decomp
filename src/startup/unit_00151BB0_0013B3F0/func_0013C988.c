#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0013C988_arg0 {
    char pad0[0x68];
    f32 unk68;
    s32 unk6C;
};

void func_0013C988(struct func_0013C988_arg0 *arg0, f32 fparg0) {
    arg0->unk68 = fparg0;
    arg0->unk6C = 0;
}
