#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003DF660();                            /* extern */
s32 func_003E14E8(s32, s32);                    /* extern */
s32 func_003E32B8(s32);                         /* extern */

void func_003E1478(s32 arg0, s32 arg1) {
    func_003DF660();
    func_003E32B8(arg0 + 0x360);
    func_003E14E8(arg0, arg1);
}
