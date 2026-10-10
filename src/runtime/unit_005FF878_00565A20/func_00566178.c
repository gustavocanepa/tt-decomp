#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00566178_temp_a0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_00566178(void **arg0, s32 arg1) {
    void *temp_a0;

    if (arg1 >= 0) {
        temp_a0 = *arg0;
        if (arg1 < ((struct func_00566178_temp_a0 *)temp_a0)->unk4) {
            return M2C_FIELD(((arg1 * 8) + temp_a0), s32 *, 0x14);
        }
    }
    return -1;
}
