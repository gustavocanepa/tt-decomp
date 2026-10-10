#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00545D78_arg0 {
    char pad0[0x10C];
    f32 unk10C;
};

void func_00545D78(struct func_00545D78_arg0 *arg0, f32 fparg0) {
    arg0->unk10C = fparg0;
}
