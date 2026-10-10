#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00560B30();                            /* extern */

s32 func_00560AF8(s32 *arg0) {
    if (*arg0 != 0) {
        func_00560B30();
    }
    return *arg0;
}
