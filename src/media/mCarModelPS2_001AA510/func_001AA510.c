/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004755EC(f32, f32, f32);               /* extern */
s32 func_00475730(f32);                         /* extern */
s32 func_00475758(f32);                         /* extern */
s32 func_00475780(f32);                         /* extern */

struct func_001AA510_arg0 {
    char pad0[0x68];
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
};

void func_001AA510(struct func_001AA510_arg0 *arg0) {
    func_004755EC(arg0->unk68, arg0->unk6C, arg0->unk70);
    func_00475780(arg0->unk7C);
    func_00475730(arg0->unk74);
    func_00475758(arg0->unk78);
}
