#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0051D710_arg0 {
    char pad0[0x120];
    f32 unk120;
};

void func_0051D710(struct func_0051D710_arg0 *arg0, f32 fparg0) {
    arg0->unk120 = fparg0;
}
