#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DAE00();                            /* extern */

struct func_00226520_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

void func_00226520(struct func_00226520_arg0 *arg0) {
    func_001DAE00();
    arg0->unkB4 = 0;
}
