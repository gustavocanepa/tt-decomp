#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004ADE50();                            /* extern */

s32 func_004ADF70(s32 *arg0) {
    s32 temp_s0;

    temp_s0 = *arg0;
    func_004ADE50();
    return temp_s0;
}
