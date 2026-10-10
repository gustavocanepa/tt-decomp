/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F4968(void *, s32);             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */
s32 func_005524A8(s32, s32);                        /* extern */

struct func_005775F0_arg0 {
    s32 unk0;
    char pad4[0x8];
    s32 unkC;
    s32 unk10;
};

void func_005775F0(struct func_005775F0_arg0 *arg0, s32 arg1) {
    func_004F64C4(func_005524A8(arg0->unkC, arg0->unk0 * arg0->unk10), arg1, arg0->unk10);
    func_004F4968(arg0, 1);
}
