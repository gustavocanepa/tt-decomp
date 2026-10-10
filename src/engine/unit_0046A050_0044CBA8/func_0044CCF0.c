#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F4E58(s32, s32, s32, s32, void *);
void func_0044CCD8();
struct func_0044CCF0_temp_v1 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_0044CCF0(void **arg0, s32 arg1) {
    s32 var_v0;
    s8 *temp_v1;
    var_v0 = 0;
    temp_v1 = *arg0;
    if (temp_v1 != NULL) {
        var_v0 = func_004F4E58(arg1, (s32)(temp_v1 + 0x10), ((struct func_0044CCF0_temp_v1 *)temp_v1)->unkC, 0x10, func_0044CCD8);
    }
    return var_v0;
}
