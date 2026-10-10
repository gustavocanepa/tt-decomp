/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F4438(void *, s32, s32);        /* extern */

struct func_004C18B8_arg1 {
    char pad0[0x54];
    s32 unk54;
};

void func_004C18B8(s32 arg0, void *arg1) {
    func_004F4438(arg1 + 0x2C, ((struct func_004C18B8_arg1 *)arg1)->unk54, 0);
}
