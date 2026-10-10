#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C00D0(s32);                         /* extern */

extern char D_005987D8[];
struct func_004BFB48_var_s0 {
    s32 unk0;
    char pad4[0x4];
    void *unk8;
};

void func_004BFB48(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    struct func_004BFB48_var_s0 *var_s0;

    var_s0 = **(void ***)D_005987D8;
    if (var_s0 != NULL) {
        do {
            func_004C00D0(var_s0->unk0);
            var_s0 = var_s0->unk8;
        } while (var_s0 != NULL);
    }
}
