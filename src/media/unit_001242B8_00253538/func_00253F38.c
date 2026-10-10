#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00257198();                              /* extern */

struct func_00253F38_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

f32 func_00253F38(struct func_00253F38_arg0 *arg0) {
    if (arg0->unkD4 == 0) {
        return M2C_FIELD(func_00257198(), f32 *, 0x18);
    }
    return M2C_FIELD(func_00257198(), f32 *, 0x14);
}
