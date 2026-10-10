#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0034BEC8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s8 func_0034BEC8(struct func_0034BEC8_arg0 *arg0, s32 arg1, s32 *arg2) {
    if (arg1 == 0) {
        return M2C_FIELD((*arg2 + arg0->unk4), s8 *, 0xC0);
    }
    return 0;
}
