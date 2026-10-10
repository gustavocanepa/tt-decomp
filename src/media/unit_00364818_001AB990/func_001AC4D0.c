/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AC160(void *);                      /* extern */
s32 func_003748D0(void *);                      /* extern */

struct func_001AC4D0_var_s0 {
    char pad0[0x2880];
    s32 unk2880;
};

void func_001AC4D0(void *arg0) {
    s32 var_s1;
    void *var_s0;

    var_s0 = arg0;
    var_s1 = 7;
    do {
        if (((struct func_001AC4D0_var_s0 *)var_s0)->unk2880 != 0) {
            func_003748D0(var_s0 + 0xFC0);
        }
        var_s1 -= 1;
        var_s0 += 0x2750;
    } while (var_s1 >= 0);
    func_001AC160(arg0);
}
