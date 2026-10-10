/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045DB08(s32);                         /* extern */
s32 func_0045DB70(s32, s32);                    /* extern */

struct func_0045DBD8_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_0045DBD8(struct func_0045DBD8_arg0 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (arg1 != 0) {
        temp_v0 = arg0->unk0;
        if (temp_v0 != 0) {
            func_0045DB08(temp_v0);
        }
        temp_v0_2 = arg0->unk4;
        if (temp_v0_2 != 0) {
            func_0045DB70(temp_v0_2, arg1);
        }
    }
}
