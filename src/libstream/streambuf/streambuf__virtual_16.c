#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 *func_004F4F80();                               /* extern */

s32 streambuf__virtual_16(void) {
    *func_004F4F80() = 5;
    return -1;
}
