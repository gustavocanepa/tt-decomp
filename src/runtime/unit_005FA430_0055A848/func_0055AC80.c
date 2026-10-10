#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0055AC80_arg0_unk60 {
    char pad0[0x8];
    s32 unk8;
};
struct func_0055AC80_arg0 {
    char pad0[0x60];
    struct func_0055AC80_arg0_unk60 *unk60;
};

s32 func_0055AC80(struct func_0055AC80_arg0 *arg0, s32 arg1) {
    return M2C_FIELD(*(s32 *)((arg1 * 4) + arg0->unk60->unk8), s32 *, 0x5450);
}
