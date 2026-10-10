#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552DF0_arg0 {
    char pad0[0xAC4];
    f32 unkAC4;
};

void func_00552DF0(struct func_00552DF0_arg0 *arg0, f32 fparg0) {
    arg0->unkAC4 = fparg0;
}
