#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_002F0508_arg0 {
    void *unk0;
    char pad4[0x23964];
    s32 unk23968;
};

s32 DynamicsConductor__GetCountDown(void *arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = M2C_FIELD(((struct func_002F0508_arg0 *)arg0)->unk0, s32 *, 0xBC);
    if ((arg1 >= 0) && (arg1 < ((struct func_002F0508_arg0 *)arg0)->unk23968)) {
        var_a2 += M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x20A4C);
    }
    return var_a2;
}
