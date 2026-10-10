#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00528D08();                            /* extern */

s32 func_00528CD0(s32 *arg0) {
    if (*arg0 != 0) {
        func_00528D08();
    }
    return *arg0;
}
