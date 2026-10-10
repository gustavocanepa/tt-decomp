/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00475950();                                /* extern */
s32 func_00475A08();                                /* extern */
s32 func_00475A48(void *, void *, void *, void *); /* extern */
s32 func_00475A88(void *, void *, void *, void *); /* extern */
s32 func_00478310(s32);                         /* extern */

struct func_00105560_arg0 {
    s32 unk0;
    char pad4[0x24];
    s32 unk28;
    s32 unk2C;
    char pad30[0x4];
    s32 unk34;
};

void func_00105560(void *arg0) {
    if (((struct func_00105560_arg0 *)arg0)->unk34 != 0) {
        func_00478310(((struct func_00105560_arg0 *)arg0)->unk0);
    }
    func_00475A48(arg0, arg0 + 4, arg0 + 8, arg0 + 0xC);
    ((struct func_00105560_arg0 *)arg0)->unk28 = func_00475A08();
    ((struct func_00105560_arg0 *)arg0)->unk2C = func_00475950();
    func_00475A88(arg0 + 0x10, arg0 + 0x14, arg0 + 0x18, arg0 + 0x1C);
}
