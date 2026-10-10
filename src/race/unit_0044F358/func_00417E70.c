#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E70_arg0 {
    char pad0[0x1F0];
    f32 unk1F0;
};

void func_00417E70(struct func_00417E70_arg0 *arg0, f32 fparg0) {
    arg0->unk1F0 = fparg0;
}
