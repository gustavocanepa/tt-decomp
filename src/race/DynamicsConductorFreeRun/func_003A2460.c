#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E69F8(s32);                         /* extern */
s32 func_002E6C08(s32);                         /* extern */
s32 func_002F04D8();                                /* extern */
s32 func_00305370(s32, s32, s32);       /* extern */

struct func_003A2460_temp_s2 {
    char pad0[0x487];
    u8 unk487;
    char pad488[0x1A8];
    s32 unk630;
};

void func_003A2460(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;
    struct func_003A2460_temp_s2 *temp_s2;

    temp_s1 = func_002F04D8();
    temp_s2 = temp_s1 + 0x104;
    if (arg1 == 0) {
        if (temp_s2->unk487 == 1) {
            func_002E6C08(temp_s1);
            func_002E69F8(temp_s1);
        }
        func_00305370(*arg0, 0, 3);
    }
    temp_s2->unk630 = arg2;
}
