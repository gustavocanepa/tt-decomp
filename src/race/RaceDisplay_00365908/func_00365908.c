/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void AutomaticFader__reset(s32);                         /* extern */

void func_00365908(void *arg0) {
    AutomaticFader__reset((s32)((char *)arg0 + 0x40));
    AutomaticFader__reset((s32)((char *)arg0 + 0x5C));
}
