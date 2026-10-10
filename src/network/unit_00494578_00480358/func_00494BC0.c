#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004967F8();                                /* extern */

extern char D_004948A8[];
extern char D_00494CA8[];
s32 func_00494BC0(s32 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 15:
        return 3;
    case 25:
        *arg0 = (s32)D_00494CA8;
        return 7;
    case 17:
        *arg0 = (s32)D_004948A8;
        return 8;
    default:
        return func_004967F8();
    }
}
