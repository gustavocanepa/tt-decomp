#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_001802A0(s32);                           /* extern */

struct func_00183D70_temp_v0 {
    char pad0[0x200];
    s32 unk200;
};

s32 func_00183D70(s32 arg0, s32 arg1) {
    s32 var_v1;
    struct func_00183D70_temp_v0 *temp_v0;

    temp_v0 = func_001802A0(arg1);
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = temp_v0->unk200;
    }
    return var_v1;
}
