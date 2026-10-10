#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D9C20();                            /* extern */
s32 func_003DF820(s32, s32);                    /* extern */
s32 func_003E31D8(s32);                         /* extern */

void func_003DF7E0(s32 arg0, s32 arg1) {
    func_003D9C20();
    func_003E31D8(arg0 + 0xF0);
    func_003DF820(arg0, arg1);
}
