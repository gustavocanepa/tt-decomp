#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0042FD90_arg0_unkE8 {
    char pad0[0x564];
    u8 unk564;
};
struct func_0042FD90_arg0 {
    char pad0[0xE4];
    s32 unkE4;
    struct func_0042FD90_arg0_unkE8 *unkE8;
};

s32 func_0042FD90(struct func_0042FD90_arg0 *arg0) {
    return M2C_FIELD(((arg0->unkE8->unk564 * 4) + arg0->unkE4), s32 *, 0x240FC);
}
