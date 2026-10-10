#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 *func_001802A0(s32);                            /* extern */

struct func_00183AD8_arg0 {
    char pad0[0x124];
    s32 unk124;
    s32 unk128;
};

void func_00183AD8(struct func_00183AD8_arg0 *arg0, s32 arg1) {
    s32 *temp_v0;

    if (arg0->unk124 == 0) {
        temp_v0 = func_001802A0(arg1);
        if ((temp_v0 != NULL) && (*temp_v0 != 0)) {
            arg0->unk128 = 0;
            arg0->unk124 = 1;
        }
    }
}
