/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00457388(s32, s32);                    /* extern */
s32 func_00457738();                            /* extern */

void func_00456F50(s32 arg0) {
    func_00457738();
    func_00457388(arg0, arg0 + 0x888);
}
