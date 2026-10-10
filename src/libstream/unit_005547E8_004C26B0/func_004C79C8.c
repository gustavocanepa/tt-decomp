#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_004C79C8_arg1 {
    s32 unk0;
    s32 unk4;
};

struct func_004C79C8_arg0 {
    char pad0[0x1F];
    s8 unk1F;
};

void func_004C79C8(void *arg0, struct func_004C79C8_arg1 *arg1) {
    M2C_FIELD(((arg1->unk0 * 4) + arg0), s32 *, 0x4C) = (s32) arg1->unk4;
    ((struct func_004C79C8_arg0 *)arg0)->unk1F = 1;
}
