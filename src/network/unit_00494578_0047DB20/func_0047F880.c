#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0047F138();                                /* extern */
s32 func_0047F8D8(void *);                      /* extern */

struct func_0047F880_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_0047F880(struct func_0047F880_arg0 *arg0) {
    s32 var_s1;

    var_s1 = -1;
    if (arg0->unk4 != 0) {
        var_s1 = func_0047F138();
        func_0047F8D8(arg0);
    }
    return var_s1;
}
