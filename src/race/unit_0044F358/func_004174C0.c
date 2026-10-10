#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00417548(s32 *);                       /* extern */
s32 func_00553D80(void *);                      /* extern */
s32 func_005666B8(s32);                         /* extern */

void func_004174C0(s32 *arg0) {
    *arg0 = 0;
    func_005666B8(arg0 + 1);
    func_00553D80(arg0 + 0xC9);
    func_00417548(arg0);
}
