#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541810_arg0 {
    char pad0[0x124];
    f32 unk124;
};

void func_00541810(struct func_00541810_arg0 *arg0, f32 fparg0) {
    arg0->unk124 = fparg0;
}
