#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 SPEC_DATABASE__DatabaseTable__getRow(s32, s32, s32);                   /* extern */

extern char D_00585C90[];
s32 func_0040F578(s32 arg0, s32 arg1) {
    return SPEC_DATABASE__DatabaseTable__getRow(*(s32 *)D_00585C90, arg0, arg1) != 0;
}
