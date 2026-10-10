#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s64 *func_00571E10(s32);                            /* extern */

s64 func_00571DB0(s32 arg0) {
    return *func_00571E10(arg0 + 8);
}
