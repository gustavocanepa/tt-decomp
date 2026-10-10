#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct func_0054A010_var_s2 {
    s32 unk0;
    s32 unk4;
};
struct func_0054A010_arg2 {
    s32 unk0;
    s32 unk4;
};

void func_0054A010(void *arg0, s32 arg1, void *arg2) {
    s32 temp_s0;
    s32 temp_v0;
    void *var_s2;

    var_s2 = arg0;
    if (var_s2 != arg1) {
        do {
            if (var_s2 != arg2) {
                ((struct func_0054A010_var_s2 *)var_s2)->unk0 = (s32) ((struct func_0054A010_arg2 *)arg2)->unk0;
            }
            if ((var_s2 + 4) != (arg2 + 4)) {
                temp_s0 = ((struct func_0054A010_arg2 *)arg2)->unk4;
                if (temp_s0 != 0) {
                    func_002C0FE8(temp_s0);
                }
                temp_v0 = ((struct func_0054A010_var_s2 *)var_s2)->unk4;
                if (temp_v0 != 0) {
                    func_002C1050(temp_v0);
                }
                ((struct func_0054A010_var_s2 *)var_s2)->unk4 = temp_s0;
            }
            var_s2 += 8;
        } while (var_s2 != arg1);
    }
}
