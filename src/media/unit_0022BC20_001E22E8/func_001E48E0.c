#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_001E48E0_arg0 {
    char pad0[0x1CE8];
    s32 unk1CE8;
};

f32 func_001E48E0(void *arg0) {
    return M2C_FIELD(((((struct func_001E48E0_arg0 *)arg0)->unk1CE8 * 0x38) + arg0), f32 *, 0x710);
}
