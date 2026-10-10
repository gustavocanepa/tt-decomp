/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00466B28(s32);                         /* extern */
s32 func_0055A788(s32, void *);                 /* extern */
s32 func_0055A7B8(void *, void *);              /* extern */

struct func_003732C0_arg0 {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
};

void func_003732C0(void *arg0) {
    func_0055A788(arg0 + 0x28, arg0);
    if (((struct func_003732C0_arg0 *)arg0)->unk2C != 0) {
        func_0055A7B8(arg0 + 0x30, arg0);
    }
    func_00466B28(((struct func_003732C0_arg0 *)arg0)->unk28);
}
