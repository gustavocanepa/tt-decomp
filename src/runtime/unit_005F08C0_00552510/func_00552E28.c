#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00552E28_arg0 {
    char pad0[0xA4C];
    s32 unkA4C;
};

s16 func_00552E28(void *arg0) {
    return M2C_FIELD(((((struct func_00552E28_arg0 *)arg0)->unkA4C * 0x1B4) + arg0), s16 *, 0x1C);
}
