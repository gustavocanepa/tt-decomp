#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001315C0(s32);                         /* extern */

struct func_001269F8_arg0 {
    char pad0[0x30C];
    s32 unk30C;
};

void func_001269F8(struct func_001269F8_arg0 *arg0) {
    func_001315C0(arg0->unk30C);
}
