#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005608F8();                            /* extern */

s32 func_00560860(s32 *arg0) {
    if (*arg0 != 0) {
        func_005608F8();
    }
    return *arg0;
}
