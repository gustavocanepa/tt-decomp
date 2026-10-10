/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6678(void *, s32, s32);    /* extern */

struct func_003A82B0_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_003A82B0(void *arg0) {
    ((struct func_003A82B0_arg0 *)arg0)->unk0 = 7;
    ((struct func_003A82B0_arg0 *)arg0)->unk4 = 0;
    func_004F6678(arg0 + 8, 0, 0xC);
}
