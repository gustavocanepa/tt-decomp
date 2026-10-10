#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_00210118();                              /* extern */

struct func_00210028_temp_v0 {
    char pad0[0x114];
    s32 unk114;
};

s32 func_00210028(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 var_v1;
    struct func_00210028_temp_v0 *temp_v0;

    temp_v0 = func_00210118();
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = temp_v0->unk114;
    }
    return var_v1;
}
