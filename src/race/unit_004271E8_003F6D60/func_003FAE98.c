/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A6448(s32, s32);                /* extern */

extern char D_005F9F80[];
void func_003FAE98(s32 *arg0) {
    func_004A6448((s32)D_005F9F80, *arg0);
}
