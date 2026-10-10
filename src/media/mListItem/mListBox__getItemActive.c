#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00257198(s32, s32);
s32 func_002571D8(s32);
s32 mListBox__getItemActive(s32 arg0, s32 arg1) {
    s32 r;
    if ((arg1 >= 0) && (arg1 < func_002571D8(arg0))) { s32 v = M2C_FIELD(func_00257198(arg0, arg1), s32 *, 0x1C); r = (v >> 17) & 1; } else r = 0;
    return r;
}
