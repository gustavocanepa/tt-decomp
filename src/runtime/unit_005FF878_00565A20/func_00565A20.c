#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s64 *func_00408B58();                               /* extern */

s32 func_00565A20(void) {
    return ~*func_00408B58() == 0;
}
