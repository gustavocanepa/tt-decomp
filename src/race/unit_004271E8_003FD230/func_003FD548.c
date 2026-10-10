#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FFB58(s32, s32);                    /* extern */

extern char D_005FA0A8[];
extern char D_005FA9F0[];
extern char D_005FA078[];
s32 func_003FD548(s32 arg0) {
    if (func_003FFB58(arg0 + 0x24, (s32)D_005FA9F0) != 0) {
        return (s32)D_005FA0A8;
    }
    return (s32)D_005FA078;
}
