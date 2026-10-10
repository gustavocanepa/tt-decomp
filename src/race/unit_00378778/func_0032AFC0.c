#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */

extern char D_005CA9E8[];
void func_0032AFC0(void *arg0, void *arg1) {
    *(s32 *)arg0 = (s32)D_005CA9E8;
    func_00321830(arg0, 0);
    if ((s32) arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
