#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_001E4CC8_arg0 {
    char pad0[0x1CE8];
    s32 unk1CE8;
};

void func_001E4CC8(void *arg0, f32 fparg0) {
    M2C_FIELD(((((struct func_001E4CC8_arg0 *)arg0)->unk1CE8 * 0x38) + arg0), f32 *, 0x73C) = fparg0;
}
