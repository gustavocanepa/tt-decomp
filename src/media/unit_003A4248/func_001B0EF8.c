/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B1240(f32);                         /* extern */

struct func_001B0EF8_arg0 {
    char pad0[0x89C];
    f32 unk89C;
};

void func_001B0EF8(struct func_001B0EF8_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 * 0x1.1df46a0000000p-6f;
    arg0->unk89C = temp_f12;
    func_001B1240(temp_f12);
}
