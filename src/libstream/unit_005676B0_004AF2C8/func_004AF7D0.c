#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF7F8(u8, u8, u8);                  /* extern */

struct func_004AF7D0_arg0 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
};

void func_004AF7D0(struct func_004AF7D0_arg0 *arg0) {
    func_004AF7F8(arg0->unk0, arg0->unk1, arg0->unk2);
}
