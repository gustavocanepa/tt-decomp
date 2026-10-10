#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0021CA78_arg0 {
    char pad0[0x78];
    f32 unk78;
};

void func_0021CA78(struct func_0021CA78_arg0 *arg0, f32 fparg0) {
    arg0->unk78 = (f32) (0x1.0000000000000p+0f / fparg0);
}
