#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00560B60(s32);                             /* extern */

void func_00560B30(s32 *arg0) {
    *arg0 = func_00560B60(*arg0);
}
