#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A148();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DA220[];
struct func_0045A0E8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_0045A0E8(struct func_0045A0E8_arg0 *arg0, s32 arg1) {
    arg0->unk1C = (s32)D_005DA220;
    func_0045A148();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
