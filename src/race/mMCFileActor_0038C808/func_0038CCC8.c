/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00356608();                            /* extern */
s32 func_0038D040(void *, s8, s32);         /* extern */

struct func_0038CCC8_arg0 {
    char pad0[0x2F];
    s8 unk2F;
};

void func_0038CCC8(struct func_0038CCC8_arg0 *arg0) {
    func_00356608();
    func_0038D040(arg0, arg0->unk2F, 0x186A0);
}
