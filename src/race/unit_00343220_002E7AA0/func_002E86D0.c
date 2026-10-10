#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050EC78(s32, s32);                    /* extern */

extern char D_00582D40[];
extern char D_00582D44[];
void func_002E86D0(s32 arg0) {
    func_0050EC78(*(s32 *)D_00582D40, *(s32 *)D_00582D44 * arg0);
}
