#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00555FC0(s32);                             /* extern */

void func_00555CA8(s32 *arg0) {
    *arg0 = func_00555FC0(*arg0);
}
