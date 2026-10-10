/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F56C0(f32, f32, f32, f32);          /* extern */
s32 func_00477DC0(s32);                         /* extern */

struct func_003F58A8_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0xC];
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
};

void func_003F58A8(struct func_003F58A8_arg0 *arg0) {
    func_00477DC0(arg0->unkC);
    func_003F56C0(arg0->unk1C, arg0->unk20, arg0->unk24, arg0->unk28);
}
