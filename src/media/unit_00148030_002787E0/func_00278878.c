#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00278878_arg0 {
    char pad0[0xDC];
    f32 unkDC;
};

void func_00278878(struct func_00278878_arg0 *arg0, f32 fparg0) {
    arg0->unkDC = fparg0;
}
