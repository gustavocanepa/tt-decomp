#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GT4Model__BinStreamWriter__writeArray(s32, s32, s32);           /* extern */
s32 func_00424178(void *, s32, s32);        /* extern */
s32 func_004241E8(void *, s32);                 /* extern */

extern char D_005F2AD8[];
void func_002DBFF0(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    func_00424178(sp, arg0, (s32)D_005F2AD8);
    GT4Model__BinStreamWriter__writeArray(arg0, arg1, 0x1814);
    func_004241E8(sp, arg0);
}
