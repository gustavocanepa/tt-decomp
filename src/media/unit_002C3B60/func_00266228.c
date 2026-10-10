#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00266440();                            /* extern */
s32 func_0042BAF8(s32);                         /* extern */

struct func_00266228_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00266228(struct func_00266228_arg0 *arg0) {
    if (arg0->unk10 != 0) {
        func_00266440();
        func_0042BAF8(arg0->unk10);
        arg0->unk10 = 0;
    }
}
