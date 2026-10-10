#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */
s32 func_003818D0(s32, s32, s32);       /* extern */

extern char D_005D9460[];
void func_00402870(s32 *arg0) {
    func_00400D68();
    *arg0 = (s32)D_005D9460;
    func_003818D0(arg0 + 1, 1, 0xAF);
}
