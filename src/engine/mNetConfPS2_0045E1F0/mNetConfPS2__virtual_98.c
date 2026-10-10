/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004A45D0(s32);                         /* extern */

struct mNetConfPS2__virtual_98_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x8];
    s32 unk14;
};

void mNetConfPS2__virtual_98(struct mNetConfPS2__virtual_98_arg0 *arg0) {
    func_004A45D0(arg0->unk8);
    func_004A45D0(arg0->unk14);
}
