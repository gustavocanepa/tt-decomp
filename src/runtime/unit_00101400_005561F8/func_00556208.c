#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00556208_arg0 {
    char pad0[0xB8];
    f32 unkB8;
    f32 unkBC;
};

void func_00556208(struct func_00556208_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unkB8 = fparg0;
    arg0->unkBC = fparg1;
}
