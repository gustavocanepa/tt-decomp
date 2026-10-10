#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553678_arg0 {
    char pad0[0x188];
    f32 unk188;
};

void func_00553678(struct func_00553678_arg0 *arg0, f32 fparg0) {
    arg0->unk188 = fparg0;
}
