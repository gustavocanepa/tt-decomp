/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 AutomaticFader__fadein(void *);                      /* extern */
s32 AutomaticFader__fadeout(void *);                      /* extern */

struct func_00351CB0_arg0 {
    char pad0[0x35];
    u8 unk35;
};

void func_00351CB0(void *arg0, s32 arg1) {
    if (((struct func_00351CB0_arg0 *)arg0)->unk35 == 0) {
        if (arg1 != 0) {
            AutomaticFader__fadein(arg0 + 0xCC);
            return;
        }
        AutomaticFader__fadeout(arg0 + 0xCC);
    }
}
