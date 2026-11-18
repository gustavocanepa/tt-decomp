#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s8 *func_00485988(s8 *arg0) {
    void *temp_s0;
    void *temp_s0_2;

    temp_s0_2 = arg0 + ((1 - M2C_FIELD(arg0, s32 *, 0x85C)) * 0x41C);
    func_00483808(arg0);
    temp_s0 = temp_s0_2 + 0x24;
    func_004B4FE0(M2C_FIELD(temp_s0, s8 **, 0xC), M2C_FIELD(temp_s0, u16 **, 8));
    return M2C_FIELD(temp_s0, s8 **, 0xC);
}
