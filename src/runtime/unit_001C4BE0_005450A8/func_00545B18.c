#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00545B18_arg0 {
    char pad0[0xF8];
    f32 unkF8;
};

void func_00545B18(struct func_00545B18_arg0 *arg0, f32 fparg0) {
    arg0->unkF8 = fparg0;
}
