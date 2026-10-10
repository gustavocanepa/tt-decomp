#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FB320(s32);                         /* extern */

struct func_003FBE48_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

s32 func_003FBE48(void *arg0, s32 arg1) {
    s32 var_v0;

    func_003FB320(arg0 + (arg1 << 5) + 8);
    var_v0 = 0;
    if (((struct func_003FBE48_arg0 *)arg0)->unk8210 == arg1) {
        ((struct func_003FBE48_arg0 *)arg0)->unk8210 = -1;
        var_v0 = 1;
    }
    return var_v0;
}
