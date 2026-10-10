#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D50_arg0 {
    char pad0[0x14C];
    f32 unk14C;
};

void func_00417D50(struct func_00417D50_arg0 *arg0, f32 fparg0) {
    arg0->unk14C = fparg0;
}
