#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FF5C0(s32);                         /* extern */

struct func_0051BDF8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0051BDF8(struct func_0051BDF8_arg0 *arg0) {
    func_003FF5C0(arg0->unk10 + 0x13AC);
}
