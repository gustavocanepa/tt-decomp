/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001EC1D8(s32, f32);                    /* extern */
s32 func_001EC208(s32);                         /* extern */

struct func_0017DB18_arg0 {
    char pad0[0xF4];
    s32 unkF4;
};

void func_0017DB18(struct func_0017DB18_arg0 *arg0, f32 fparg0) {
    func_001EC208(arg0->unkF4);
    func_001EC1D8(arg0->unkF4, fparg0);
}
