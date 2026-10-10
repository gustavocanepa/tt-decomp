/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033CA70(s32);                             /* extern */
s32 DisplayRText__getRTextStr(s32);                             /* extern */
s32 func_004A6500(void *, s32, s32, s32);   /* extern */

extern char D_005F7550[];
struct func_0037FC78_arg0 {
    char pad0[0x84C];
    s32 unk84C;
};

void func_0037FC78(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v0_2;

    ((struct func_0037FC78_arg0 *)arg0)->unk84C = arg3;
    temp_v0 = func_0033CA70(arg1);
    temp_v0_2 = DisplayRText__getRTextStr(temp_v0);
    func_004A6500(arg0 + 0x80C, (s32)D_005F7550, (temp_v0_2 != 0) ? temp_v0_2 : temp_v0, arg2);
}
