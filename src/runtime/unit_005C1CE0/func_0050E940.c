/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AEAC0(s32);                         /* extern */
s32 func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */

struct func_0050E940_arg0 {
    char pad0[0x9C];
    s32 unk9C;
    s32 unkA0;
};

void func_0050E940(void *arg0, s32 arg1) {
    func_004A4D68();
    func_004AEAC0(arg0 + 0x6C);
    ((struct func_0050E940_arg0 *)arg0)->unk9C = arg1;
    ((struct func_0050E940_arg0 *)arg0)->unkA0 = 1;
    func_004A4DD8(arg0);
}
