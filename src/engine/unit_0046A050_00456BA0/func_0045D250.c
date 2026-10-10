#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045D2B0();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA268[];
struct func_0045D250_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_0045D250(struct func_0045D250_arg0 *arg0, s32 arg1) {
    arg0->unk20 = (s32)D_005DA268;
    func_0045D2B0();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
