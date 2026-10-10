/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041CA18(f32, f32, f32, f32);          /* extern */
s32 func_0041CA38(f32, f32);                    /* extern */

struct func_0034E3E0_arg0 {
    char pad0[0x17B4];
    f32 unk17B4;
    f32 unk17B8;
    f32 unk17BC;
    f32 unk17C0;
    f32 unk17C4;
    f32 unk17C8;
};

void func_0034E3E0(struct func_0034E3E0_arg0 *arg0) {
    func_0041CA18(arg0->unk17B4, arg0->unk17B8, arg0->unk17BC, arg0->unk17C0);
    func_0041CA38(arg0->unk17C4, arg0->unk17C8);
}
