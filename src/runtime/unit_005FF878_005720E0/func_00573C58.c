#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00573C90();                            /* extern */

s32 func_00573C58(s32 *arg0) {
    if (*arg0 != 0) {
        func_00573C90();
    }
    return *arg0;
}
