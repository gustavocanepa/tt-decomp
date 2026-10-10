#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00369150(s32);                         /* extern */
s32 func_0040BBD0();                            /* extern */

void func_0037AFA8(s32 arg0) {
    func_0040BBD0();
    func_00369150(arg0 + 0x190);
}
