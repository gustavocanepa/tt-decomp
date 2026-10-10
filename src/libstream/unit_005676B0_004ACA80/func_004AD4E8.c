#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u32 func_004AD378(void *);                          /* extern */
u32 *func_004AD560();                               /* extern */

struct func_004AD4E8_arg0 {
    char pad0[0x44];
    u32 *unk44;
};

u32 *func_004AD4E8(struct func_004AD4E8_arg0 *arg0, u32 arg1) {
    u32 *var_s0;

    var_s0 = func_004AD560();
    if ((var_s0 == NULL) && (func_004AD378(arg0) >= (u32) (arg1 + 4))) {
        var_s0 = arg0->unk44;
        *var_s0 = arg1;
        arg0->unk44 = (u32 *) (&var_s0[arg1 >> 2] + 1);
    }
    return var_s0;
}
