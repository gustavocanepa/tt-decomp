#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

s32 func_0033CB60(s32);
s32 func_0040EE28(s32);
struct func_00373210_arg0 {
    char pad0[0x6C];
    void *unk6C;
};

void func_00373210(s8 *arg0) {
    s32 *p = (s32 *)(arg0 + 0xE2C);
    s32 temp_v0;
    if ((*p ^ 0xF) == 0) {
        temp_v0 = func_0033CB60(func_0040EE28(M2C_FIELD(((struct func_00373210_arg0 *)arg0)->unk6C, s32 *, 0x70)));
        if (temp_v0 != 0) {
            *p = temp_v0;
        }
    }
}
