#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004001C8(s32);                         /* extern */

struct func_0051BFF8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_0051BFF8(struct func_0051BFF8_arg0 *arg0) {
    func_004001C8(arg0->unk10 + 0x16B8);
}
