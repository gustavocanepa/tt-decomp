#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052C748_arg0 {
    char pad0[0xEC];
    f32 unkEC;
};

void func_0052C748(struct func_0052C748_arg0 *arg0, f32 fparg0) {
    arg0->unkEC = fparg0;
}
