#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042DCF8(void *);                      /* extern */

struct func_0034E768_arg0 {
    s32 unk0;
    char pad4[0x168];
    f32 unk16C;
};

s32 func_0034E768(void *arg0) {
    s32 var_s2;
    void *temp_a0;
    void *var_s0;

    var_s0 = arg0 + 4;
    var_s2 = 4;
    ((struct func_0034E768_arg0 *)arg0)->unk0 = 0;
    do {
        temp_a0 = var_s0;
        var_s0 += 0x24;
        var_s2 -= 1;
        func_0042DCF8(temp_a0);
    } while (var_s2 != -1);
    func_0042DCF8(arg0 + 0xB8);
    func_0042DCF8(arg0 + 0xDC);
    func_0042DCF8(arg0 + 0x100);
    func_0042DCF8(arg0 + 0x124);
    func_0042DCF8(arg0 + 0x148);
    ((struct func_0034E768_arg0 *)arg0)->unk16C = 0.125f;
}
