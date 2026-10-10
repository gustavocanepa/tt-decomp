/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046CE60(s32, f32);                /* extern */

struct func_0041B810_arg0 {
    char pad0[0x44];
    f32 unk44;
};

void func_0041B810(struct func_0041B810_arg0 *arg0) {
    func_0046CE60(0, 0x1.0000000000000p+0f - arg0->unk44);
}
