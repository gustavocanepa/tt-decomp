#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004B50B0(const u16 *);
s32 func_004858F0(void *arg0, s8 *arg1, s32 arg2) {
    void *temp_s1;

    temp_s1 = arg0 + ((1 - M2C_FIELD(arg0, s32 *, 0x85C)) * 0x41C) + 0x24;
    func_00483808(arg0);
    if (func_004B50B0(M2C_FIELD(temp_s1, u16 **, 8)) >= arg2) {
        *arg1 = 0;
        return 0;
    }
    func_004B4FE0(arg1, M2C_FIELD(temp_s1, u16 **, 8));
    return 1;
}
