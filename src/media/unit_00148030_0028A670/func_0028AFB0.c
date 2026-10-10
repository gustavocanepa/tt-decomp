#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DAE00();                            /* extern */

struct func_0028AFB0_arg0 {
    char pad0[0x9C];
    s32 unk9C;
};

void func_0028AFB0(struct func_0028AFB0_arg0 *arg0) {
    func_001DAE00();
    arg0->unk9C = 0;
}
