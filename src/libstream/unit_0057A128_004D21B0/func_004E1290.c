#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004E11F8();                                /* extern */

s32 func_004E1290(void) {
    s32 temp_v0;

    temp_v0 = func_004E11F8();
    return (~temp_v0 == 0) ? 0 : temp_v0;
}
