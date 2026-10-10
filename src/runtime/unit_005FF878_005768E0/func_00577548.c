/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F4908(void *, s32);             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */
s32 func_005524A8(s32, s32);                        /* extern */

struct func_00577548_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
};

void func_00577548(struct func_00577548_arg0 *arg0, s32 arg1) {
    func_004F64C4(arg1, func_005524A8(arg0->unkC, arg0->unk4 * arg0->unk10), arg0->unk10);
    func_004F4908(arg0, 1);
}
