#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002D8B18(void *);                      /* extern */
s32 func_002E42C8(s32, s32, s32, u32);      /* extern */

struct func_002D8D20_arg0 {
    char pad0[0x10];
    s32 unk10;
};

s32 func_002D8D20(struct func_002D8D20_arg0 *arg0, u32 arg1) {
    s32 temp_s0;

    if (arg1 < 5U) {
        temp_s0 = func_002E42C8(arg0->unk10, 4, 0, arg1);
        func_002D8B18(arg0);
        return temp_s0 > 0;
    }
    return 0;
}
