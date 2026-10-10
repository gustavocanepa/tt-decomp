#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DB3B0[];
void func_004CDFA0(void *arg0, void *arg1) {
    *(s32 *)arg0 = (s32)D_005DB3B0;
    func_004C9F30(arg0, 0);
    if ((s32) arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
