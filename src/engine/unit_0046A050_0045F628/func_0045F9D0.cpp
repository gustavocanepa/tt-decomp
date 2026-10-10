extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

s32 func_0045F9D0(char *arg0) {
    s32 temp_a0;
    s32 var_v0;

    temp_a0 = M2C_FIELD(arg0, s32 *, 0xAC);
    var_v0 = 0;
    if (temp_a0 >= 0) {
        var_v0 = (M2C_FIELD(arg0, s32 *, 0xA0) < temp_a0) == 0;
    }
    return var_v0;
}

}
