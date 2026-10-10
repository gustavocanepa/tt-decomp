#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003DF660();                            /* extern */
s32 func_003E32B8(s32);                         /* extern */

void func_003E1450(s32 arg0) {
    func_003DF660();
    func_003E32B8(arg0 + 0x360);
}
