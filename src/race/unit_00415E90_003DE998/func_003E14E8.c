#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003DF820();                            /* extern */
s32 func_003E3A60(s32, s32);                    /* extern */

s32 func_003E14E8(s32 arg0, s32 arg1) {
    func_003DF820();
    func_003E3A60(arg0 + 0x360, arg1 + 0x360);
    return arg0;
}
