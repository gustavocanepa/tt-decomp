/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FDC30(s32, s32, s32);           /* extern */

struct func_0051B950_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0051B950(struct func_0051B950_arg0 *arg0, s32 arg1) {
    func_003FDC30(arg0->unk10, 0x80, arg1);
}
