#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct hLocalVariable__virtual_17_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void hLocalVariable__assign(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0x14) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = ((struct hLocalVariable__virtual_17_arg0 *)arg0)->unk14;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        ((struct hLocalVariable__virtual_17_arg0 *)arg0)->unk14 = temp_s0;
    }
}
