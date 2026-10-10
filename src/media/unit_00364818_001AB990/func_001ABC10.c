#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001AF720(s32);                         /* extern */

struct func_001ABC10_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_001ABC10(struct func_001ABC10_arg0 *arg0, s32 arg1) {
    func_001AF720(arg0->unk4);
    M2C_FIELD(((arg1 * 0x48) + arg0->unk4), s32 *, 0x14138) = 1;
}
