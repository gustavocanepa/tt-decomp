#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00555D38();                            /* extern */

s32 func_00555E58(s32 *arg0) {
    if (*arg0 != 0) {
        func_00555D38();
    }
    return *arg0;
}
