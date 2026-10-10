#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005513C0_arg0 {
    char pad0[0xD00C];
    f32 unkD00C;
};

void func_005513C0(struct func_005513C0_arg0 *arg0, f32 fparg0) {
    arg0->unkD00C = fparg0;
}
