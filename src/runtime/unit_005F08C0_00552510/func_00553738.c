#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553738_arg0 {
    char pad0[0x260];
    f32 unk260;
};

void func_00553738(struct func_00553738_arg0 *arg0, f32 fparg0) {
    arg0->unk260 = fparg0;
}
