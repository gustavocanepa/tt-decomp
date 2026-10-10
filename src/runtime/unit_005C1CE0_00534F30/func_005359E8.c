#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005359E8_arg0 {
    char pad0[0xBC];
    f32 unkBC;
};

void func_005359E8(struct func_005359E8_arg0 *arg0, f32 fparg0) {
    arg0->unkBC = fparg0;
}
