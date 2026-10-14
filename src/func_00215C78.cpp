#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 ModelSet2__render(s32, s32);                    /* extern */
s32 func_00421C40(s32);                     /* extern */
s32 func_00421C68(s32);                     /* extern */
s32 func_0041A170(f32);                         /* extern */
s32 func_0046F0F8(s32);                     /* extern */
s32 func_0046F470(s32);                     /* extern */
s32 func_0046F498(s32);                     /* extern */
s32 func_00478C98(s32);                     /* extern */

struct mModelSetPS2__virtual_09_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void mModelSetPS2__virtual_09(struct mModelSetPS2__virtual_09_arg0 *arg0, s32 arg1) {
    func_0041A170(0x1.0000000000000p+0f);
    func_00421C40(1);
    func_00421C68(0);
    func_0046F0F8(0xF);
    func_0046F498(arg1 != 0);
    func_0046F470(2);
    ModelSet2__render(arg0->unk8, 0);
    func_00478C98(0xF);
}

}
