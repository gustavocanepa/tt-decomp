#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0043DC08(s32);                         /* extern */

struct func_004415A8_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_004415A8(void *arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x14;
    if ((((struct func_004415A8_arg0 *)arg0)->unk14 ^ 7) != 0) {
        func_0043DC08(temp_s0);
    }
    return temp_s0;
}
