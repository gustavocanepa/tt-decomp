#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00406128_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

u16 func_00406128(void *arg0, s32 arg1) {
    return M2C_FIELD(((((((struct func_00406128_arg0 *)arg0)->unk4D8 * 0xC8) + arg1) * 2) + arg0), u16 *, 0x118);
}
