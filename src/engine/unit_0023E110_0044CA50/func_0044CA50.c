/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0056CFD8(s32, s32);                    /* extern */

void func_0044CA50(void *arg0, s32 arg1) {
    func_0056CFD8((s32)arg0, arg1);
    func_0056CFD8((s32)((char *)arg0 + 4), arg1);
}
