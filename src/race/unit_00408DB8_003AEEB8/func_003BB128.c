#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 pdiRiderman__Skeleton__getBoneIndex();                                /* extern */

extern char D_00769010[];
s32 func_003BB128(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    return (pdiRiderman__Skeleton__getBoneIndex() << 6) + (s32)D_00769010;
}
