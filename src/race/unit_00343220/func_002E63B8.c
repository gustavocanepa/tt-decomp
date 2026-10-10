#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

typedef struct { u8 p0; u8 n; u8 pad[0x12]; u8 b[1]; } V;
V *func_002FD378(s32);
typedef struct { u8 pad[0x2E8]; f32 f[1]; } T;
f32 func_002E63B8(void *arg0, s32 arg1) {
    f32 var_f0;
    V *temp_v0;
    temp_v0 = func_002FD378(M2C_FIELD(arg0, s32 *, 0x10));
    var_f0 = 0.0f;
    if (arg1 < temp_v0->n) {
        var_f0 = M2C_FIELD(arg0, T **, 0x10)->f[temp_v0->b[arg1]];
    }
    return var_f0;
}
