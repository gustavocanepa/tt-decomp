#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536C40_arg0 {
    char pad0[0xD0];
    f32 unkD0;
};

void func_00536C40(struct func_00536C40_arg0 *arg0, f32 fparg0) {
    arg0->unkD0 = fparg0;
}
