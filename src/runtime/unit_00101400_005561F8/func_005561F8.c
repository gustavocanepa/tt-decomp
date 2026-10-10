#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005561F8_arg0 {
    char pad0[0xB0];
    f32 unkB0;
    f32 unkB4;
};

void func_005561F8(struct func_005561F8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unkB0 = fparg0;
    arg0->unkB4 = fparg1;
}
