/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C3588(s32);                         /* extern */
s32 func_002C39C8(s32, s32, s32);               /* extern */

struct func_002CD120_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
};

void func_002CD120(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1C;
    func_002C3588(temp_s1);
    func_002C39C8(temp_s1, ((struct func_002CD120_arg0 *)arg0)->unkC, ((struct func_002CD120_arg0 *)arg0)->unk10);
}
