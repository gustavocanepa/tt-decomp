#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00481718(s32);                         /* extern */

struct func_0056F188_arg1 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_0056F188(s32 arg0, struct func_0056F188_arg1 *arg1) {
    s32 temp_v0;

    temp_v0 = arg1->unk48;
    if (temp_v0 != 0) {
        func_00481718(temp_v0);
    }
}
