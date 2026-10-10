#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0030E928(s32);                             /* extern */

struct func_002D7F68_arg1 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_002D7F68(s32 arg0, struct func_002D7F68_arg1 *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != NULL) {
        var_v0 = func_0030E928(arg1->unk18) >= 3;
    }
    return var_v0;
}
