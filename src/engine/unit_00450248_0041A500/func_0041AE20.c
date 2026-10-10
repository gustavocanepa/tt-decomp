#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041AE20_arg0 {
    char pad0[0x48];
    f32 unk48;
};

void func_0041AE20(struct func_0041AE20_arg0 *arg0, f32 fparg0) {
    arg0->unk48 = fparg0;
}
