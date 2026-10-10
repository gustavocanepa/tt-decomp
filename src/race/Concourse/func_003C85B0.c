#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003C8690();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D7108[];
struct func_003C85B0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_003C85B0(struct func_003C85B0_arg0 *arg0, s32 arg1) {
    arg0->unk10 = (s32)D_005D7108;
    func_003C8690();
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
