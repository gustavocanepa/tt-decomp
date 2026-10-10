#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417E20_arg0 {
    char pad0[0x1DC];
    f32 unk1DC;
};

void func_00417E20(struct func_00417E20_arg0 *arg0, f32 fparg0) {
    arg0->unk1DC = fparg0;
}
