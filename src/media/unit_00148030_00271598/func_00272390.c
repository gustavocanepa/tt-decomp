#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DAE00();                            /* extern */

struct func_00272390_arg0 {
    char pad0[0x94];
    s32 unk94;
};

void func_00272390(struct func_00272390_arg0 *arg0) {
    func_001DAE00();
    arg0->unk94 = 0;
}
