#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00455BA8();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA100[];
struct func_00455B48_arg0 {
    char pad0[0x24];
    s32 unk24;
};

void func_00455B48(struct func_00455B48_arg0 *arg0, s32 arg1) {
    arg0->unk24 = (s32)D_005DA100;
    func_00455BA8();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
