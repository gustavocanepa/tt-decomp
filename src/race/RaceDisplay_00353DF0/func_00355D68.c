#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

extern char D_005F4260[];
struct func_00355D68_arg0 {
    char pad0[0x4];
    void *unk4;
    s32 unk8;
};

s32 func_00355D68(s32 arg0, s32 arg1) {
    if ((((struct func_00355D68_arg0 *)arg0)->unk8 != 0) && (arg1 >= 0) && (arg1 < *M2C_FIELD(((struct func_00355D68_arg0 *)arg0)->unk4, s32 **, 0x60))) {
        func_00359638(arg0 + 0x14D8, (s32)D_005F4260);
    }
}
