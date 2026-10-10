#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002D8B18(void *);                      /* extern */
s32 func_002E42C8(s32, s32, s32, s32);      /* extern */

struct func_002D8E28_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x40];
    s32 unk54;
};

s32 func_002D8E28(struct func_002D8E28_arg0 *arg0) {
    s32 temp_s1;

    temp_s1 = func_002E42C8(arg0->unk10, 6, 0, (arg0->unk54 + 1) & 1);
    func_002D8B18(arg0);
    return temp_s1 > 0;
}
