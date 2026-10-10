/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004755EC(f32, f32, f32);               /* extern */
s32 func_00475730(f32);                         /* extern */
s32 func_00475758(f32);                         /* extern */
s32 func_00475780(f32);                         /* extern */

struct func_0017A5C8_arg0 {
    char pad0[0x2C];
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    char pad3C[0x8];
    f32 unk44;
    f32 unk48;
};

void func_0017A5C8(struct func_0017A5C8_arg0 *arg0) {
    func_004755EC(arg0->unk2C, arg0->unk30, arg0->unk34);
    func_00475780(arg0->unk48);
    func_00475730(arg0->unk38);
    func_00475758(arg0->unk44);
}
