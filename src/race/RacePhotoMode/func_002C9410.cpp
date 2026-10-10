extern "C" {
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

s32 func_0034A648(...) throw();
void RaceCourse__clearData(...) throw();

struct func_002C9410_arg0 {
    char pad0[0x6C];
    char *unk6C;
    char pad70[0x3272C];
    s32 unk3279C;
};

void func_002C9410(char *arg0) {
    RaceCourse__clearData(M2C_FIELD(((struct func_002C9410_arg0 *)arg0)->unk6C, s32 *, 0x80));
    if (((struct func_002C9410_arg0 *)arg0)->unk3279C == 0) {
        ((struct func_002C9410_arg0 *)arg0)->unk3279C = func_0034A648();
    }
}

}
