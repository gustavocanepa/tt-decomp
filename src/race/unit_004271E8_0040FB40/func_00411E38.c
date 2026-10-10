#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00412368();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D9848[];
struct func_00411E38_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00411E38(struct func_00411E38_arg0 *arg0, s32 arg1) {
    arg0->unk10 = (s32)D_005D9848;
    func_00412368();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
