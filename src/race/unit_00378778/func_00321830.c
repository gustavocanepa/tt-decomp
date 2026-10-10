#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050E1A8(void *);                      /* extern */

extern char D_005C9AB0[];
void func_00321830(void *arg0, void *arg1) {
    *(s32 *)arg0 = (s32)D_005C9AB0;
    func_00416E78(arg0, 0);
    if ((s32) arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
