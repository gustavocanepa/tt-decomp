/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00346908(s32, s32);                /* extern */

extern char D_00585F40[];
void func_003474E8(s32 arg0) {
    func_00346908(arg0 + 0x15C, (s32)D_00585F40);
}
