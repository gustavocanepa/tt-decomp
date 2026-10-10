/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002DB928(s32, void *, f32);            /* extern */
s32 func_002E2338(s32, s32, s32);               /* extern */
s32 func_004228E0(s32, s32, f32);               /* extern */
s32 func_00424178(void *, s32, s32);        /* extern */
s32 func_004241E8(void *, s32);                 /* extern */

extern char D_005F2AC0[];
struct func_002DBCF0_arg1 {
    char pad0[0x14];
    s32 unk14;
};

void func_002DBCF0(s32 arg0, void *arg1, s32 arg2, s32 arg3, f32 fparg0) {
    s8 sp[0x10];
    func_00424178(sp, arg0, (s32)D_005F2AC0);
    func_004228E0(arg0, arg1 + 0x4850, fparg0);
    func_002DB928(arg0, arg1, fparg0);
    if (arg3 != 0) {
        func_002E2338(arg2 + 0x3290, arg0, ((struct func_002DBCF0_arg1 *)arg1)->unk14);
    }
    func_004241E8(sp, arg0);
}
