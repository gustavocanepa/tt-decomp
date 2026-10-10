#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004816D0(s32);                             /* extern */
s32 func_004816F0(s32);                         /* extern */
u32 func_004A8368(s32);                             /* extern */
s32 func_004F7B74(s32, s32);                    /* extern */

struct func_00480568_arg1 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_00480568(s32 arg0, struct func_00480568_arg1 *arg1, s32 arg2, u32 arg3) {
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s4;

    var_s4 = 0;
    temp_s3 = arg1->unk48;
    temp_v0 = func_004816D0(temp_s3);
    if (func_004A8368(temp_v0) < arg3) {
        var_s4 = 1;
        func_004F7B74(arg2, temp_v0);
    }
    func_004816F0(temp_s3);
    return var_s4;
}
