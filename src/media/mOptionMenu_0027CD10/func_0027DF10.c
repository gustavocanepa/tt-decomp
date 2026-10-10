/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0027D4F8(s32);                         /* extern */
s32 func_0027E010(s32);                         /* extern */
s32 func_004AC580(s32);                         /* extern */

void func_0027DF10(s32 arg0) {
    func_004AC580(arg0 + 0xE0);
    func_0027E010(arg0);
    func_0027D4F8(arg0);
}
