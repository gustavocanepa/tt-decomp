#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u8 func_00301F08();                                 /* extern */

struct func_00302660_arg0 {
    char pad0[0x7EA];
    u8 unk7EA;
};

u8 func_00302660(struct func_00302660_arg0 *arg0) {
    u8 var_v0;

    var_v0 = func_00301F08();
    if (var_v0 != 0) {
        var_v0 = arg0->unk7EA;
    }
    return var_v0;
}
