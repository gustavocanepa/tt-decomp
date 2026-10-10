#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00560FD8();                            /* extern */

s32 func_00560F30(s32 *arg0) {
    if (*arg0 != 0) {
        func_00560FD8();
    }
    return *arg0;
}
