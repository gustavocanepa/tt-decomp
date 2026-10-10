/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0032F458(s32, s32, s32);               /* extern */
s32 func_003444F0();                                /* extern */
s32 func_003458F0(void *, s32);             /* extern */

struct func_00345630_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00345630(struct func_00345630_arg0 *arg0, s32 arg1) {
    func_0032F458(func_003444F0(), arg0->unk4, arg1);
    func_003458F0(arg0, 1);
    func_003458F0(arg0, 1);
}
