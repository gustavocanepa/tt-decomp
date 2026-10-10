#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00555C78();                            /* extern */

s32 func_0055DA08(s32 *arg0) {
    if (*arg0 != 0) {
        func_00555C78();
    }
    return *arg0;
}
