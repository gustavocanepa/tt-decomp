#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D8280();                            /* extern */
s32 func_003D8F78(s32, s32);                    /* extern */
s32 func_003E32B8(s32);                         /* extern */

void func_003D8F08(s32 arg0, s32 arg1) {
    func_003D8280();
    func_003E32B8(arg0 + 0x170);
    func_003D8F78(arg0, arg1);
}
