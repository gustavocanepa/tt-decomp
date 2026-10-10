#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_002A7590(void *, void *);              /* extern */

struct func_0054A128_var_s0 {
    s32 unk0;
};
struct func_0054A128_arg2 {
    s32 unk0;
};

void *func_0054A128(void *arg0, s32 arg1, void *arg2) {
    s32 var_s1;
    void *var_s0;

    var_s1 = arg1;
    var_s0 = arg0;
    if (var_s1 != 0) {
        do {
            if (var_s0 != NULL) {
                ((struct func_0054A128_var_s0 *)var_s0)->unk0 = ((struct func_0054A128_arg2 *)arg2)->unk0;
                func_002A7590(var_s0 + 4, arg2 + 4);
            }
            var_s1 -= 1;
            var_s0 += 8;
        } while (var_s1 != 0);
    }
    return var_s0;
}
