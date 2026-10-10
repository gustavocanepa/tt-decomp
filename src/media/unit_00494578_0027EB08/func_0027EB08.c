/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0027D4F8(void *);                      /* extern */
s32 func_001DC9F0(s32);                         /* extern */

void func_0027EB08(void *arg0) {
    func_001DC9F0((s32)((char *)arg0 + 0xB4));
    func_0027D4F8(arg0);
}
