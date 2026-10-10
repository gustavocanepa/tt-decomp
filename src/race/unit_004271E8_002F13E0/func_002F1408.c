#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u8 func_00305BE8(void *);                           /* extern */

struct func_002F1408_temp_s0 {
    char pad0[0x4E];
    u8 unk4E;
};

u8 func_002F1408(s32 arg0) {
    u8 var_v0;
    struct func_002F1408_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x238E0;
    var_v0 = func_00305BE8(temp_s0);
    if (var_v0 == 0) {
        var_v0 = temp_s0->unk4E;
    }
    return var_v0;
}
