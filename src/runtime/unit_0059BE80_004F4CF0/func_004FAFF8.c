#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00503F90(s32);                         /* extern */

s32 func_004FAFF8(s32 arg0, s32 arg1) {
    if (arg0 == 1) {
        func_00503F90(arg1);
    }
    return 0;
}
