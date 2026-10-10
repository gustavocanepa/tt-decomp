#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0050ED08_arg0 {
    char pad0[0xB0];
    f32 unkB0;
};

void func_0050ED08(struct func_0050ED08_arg0 *arg0, f32 fparg0) {
    arg0->unkB0 = (f32) (arg0->unkB0 + fparg0);
}
