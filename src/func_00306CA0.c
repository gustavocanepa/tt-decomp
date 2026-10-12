#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00306CA0(void *arg0) {
    return (s32) ((f32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), u16 *, 0x26C) * M2C_FIELD(arg0, f32 *, 0x63C));
}
